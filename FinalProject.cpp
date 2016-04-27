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
	Person *unknownPerson = new Person("Unknown");
	unknownPerson -> setVisited(true);
	myFamilyTree -> setUnknownPerson(unknownPerson);
	bool done = false;
	while (!done)		//write menu
	{
		cout << "======Main Menu======" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Print Persons Information" << endl;
		cout << "3. Print all Roots" << endl;
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
			cout << "What is " << name << "'s biological mothers full name, \"First Last\"? If you do not know put \"Unknown\"." << endl;
			string mothersName;
			getline(cin, mothersName);
			cout << "What is " << name << "'s biological fathers full name, \"First Last\"? If you do not know put \"Unknown\"." << endl;
			string fathersName;
			getline(cin, fathersName);
			cout << "Does " << name << " have a spouse? If so, enter their full name, \"First Last\", if not enter \"None\", and if you do not know, enter \"Unknown\"." << endl;
			string spouse;
			getline(cin, spouse);
			cout << "Is " << name << " a male or female? For male enter \"m\" and for female enter \"f\"." << endl;
			string gender = "";
			bool doneWithGender = false;
			while (!doneWithGender)
			{
				getline(cin, gender);
				if (gender == "m" || gender == "f")
				{
					//cout << endl;
					doneWithGender = true;
				}
				else
					cout << "This is not a recognized input, please try again:";
			}
			Person *newPerson = new Person(name, mothersName, fathersName, spouse, gender);
			cout << "Does " << newPerson -> getFullName() << " have any siblings? "; 
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
					cout << "Does " << newPerson -> getFullName() << " have any more siblings? ";
				}
			}
			cout << "Does " << newPerson -> getFullName() << " have any children?"; 
			bool doneWithChildren = false;
			while (!doneWithChildren)
			{
				cout << " If not enter \"No\", otherwise enter their full name, \"First Last\": ";
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
			myFamilyTree -> addToTree(newPerson);
		}
		else if (userChoiceString == "2")
		{
			cout << "What is the persons full name(\"First Last)\"?:" << endl;
			cin.ignore();
			string name;
			getline(cin, name);
			//myFamilyTree -> resetVisited();
			Person *person = myFamilyTree -> findPerson(name);
			if (person != NULL)
			{
				person -> printInformation();
			}
		}
		else if (userChoiceString == "3")
		{
			myFamilyTree -> printAllRoots();
		}
		else if (userChoiceString == "5")
		{
			cout << "Goodbye!" << endl; 
			done = true;
		}
	}
	return 0;
}
