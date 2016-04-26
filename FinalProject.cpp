/*
	Adam Austin
	4/22/2016
	TA: Quesada
*/

#include "Person.h"
#include "FamilyTree.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
	FamilyTree *myFamilyTree = new FamilyTree();
	bool done = false;
	while (!done)		//write menu
	{
		cout << "======Main Menu======" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Print Persons Information" << endl;
		cout << "5. Quit" << endl;
		string userChoiceString;
		cin >> userChoiceString;
		
		// Check user input
		if (userChoiceString == "1")
		{
			cout << "What is the persons full name(\"First Last)\"?:" << endl;
			cin.ignore();
			string name;
			getline(cin, name);
			cout << "What is your biological mothers full name, \"First Last\"? If you do not know put \"Unknown\"" << endl;
			string mothersName;
			getline(cin, mothersName);
			cout << "What is your biological fathers full name, \"First Last\"? If you do not know put \"Unknown\"" << endl;
			string fathersName;
			getline(cin, fathersName);
			Person *newPerson = new Person(name, mothersName, fathersName, myFamilyTree);
			myFamilyTree -> addToTree(newPerson);
			
			cout << "Does " << newPerson -> getFullName() << " have any siblings?"; 
			bool doneWithSiblings = false;
			while (!doneWithSiblings)
			{
				cout << "If not enter \"No\", otherwise enter their full name, \"First Last\": ";
				//cin.ignore();
				string userInput;
				getline(cin, userInput);
				//cout << "answer was " << userInput << endl;
				if (userInput == "No")
				{
					doneWithSiblings = true;
					//cout << "SAID NO" << endl;
				}
				else
				{
					cout << userInput << " is a sibling? Enter \"Yes \" or \"No\": ";
					string confirm;
					getline(cin, confirm);
					if (confirm == "Yes")
					{
						cout << userInput << " has been added!" << endl;
						Person *newSib = new Person(userInput, myFamilyTree);
						newSib -> addSibling(newPerson);
						newPerson -> addSibling(newSib);
					}
					else
						cout << userInput << " has not been added as a sibling" << endl;
					cout << "Does " << newPerson -> getFullName() << " have any more siblings?";
				}
			}
			cout << "Does " << newPerson -> getFullName() << " have any children?"; 
			bool doneWithChildren = false;
			while (!doneWithChildren)
			{
				cout << "If not enter \"No\", otherwise enter their full name, \"First Last\": ";
				//cin.ignore();
				string userInput;
				getline(cin, userInput);
				//cout << "answer was " << userInput << endl;
				if (userInput == "No")
				{
					doneWithChildren = true;
					//cout << "SAID NO" << endl;
				}
				else
				{
					cout << userInput << " is a child? Enter \"Yes \" or \"No\": ";
					string confirm;
					getline(cin, confirm);
					if (confirm == "Yes")
					{
						cout << userInput << " has been added!" << endl;
						Person *newChild = new Person(userInput, myFamilyTree);
						//newChild -> setBi(newPerson);
						newPerson -> addChild(newChild);
					}
					else
						cout << userInput << " has not been added as a child" << endl;
					cout << "Does " << newPerson -> getFullName() << " have any more children?";
				}
			}
		}
		else if (userChoiceString == "2")
		{
			cout << "What is the persons full name(\"First Last)\"?:" << endl;
			cin.ignore();
			string name;
			getline(cin, name);
			myFamilyTree -> resetVisited();
			Person *person = myFamilyTree -> findPerson(name);
			if (person != NULL)
			{
				cout << "=====================" << endl;
				cout << "Name: " << person -> getFullName() << endl;
				if (person -> getBiologicalMother() != NULL)
					cout << "Mother: " << person -> getBiologicalMother() -> getFullName() << endl;
				if (person -> getBiologicalFather() != NULL)
					cout << "Father: " << person -> getBiologicalFather() -> getFullName() << endl;
				cout << "Siblings";
				for (int i = 0; i < person -> sibList.size(); i++)
				{
					cout << ", " << person -> sibList[i] -> getFullName();
				}
				cout << endl;
				cout << "Children";
				for (int i = 0; i < person -> childList.size(); i++)
				{
					cout << ", " << person -> childList[i] -> getFullName();
				}
				cout << endl;
			}
		}
		else if (userChoiceString == "5")
		{
			cout << "Goodbye!" << endl; 
			done = true;
		}
	}
	return 0;
}
