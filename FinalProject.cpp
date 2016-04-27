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
	FamilyTree *myFamilyTree = new FamilyTree();						// Create an instance of familyTree
	Person *unknownPerson = new Person("Unknown");						// Make an unknown node for the tree whose visited will always be true. This will help with people with unknown relatives
	unknownPerson -> setVisited(true);
	myFamilyTree -> setUnknownPerson(unknownPerson);					// Set the unknown person to myFamilyTree
	bool done = false;
	while (!done)										//write menu
	{
		cout << "======Main Menu======" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Print Persons Information" << endl;
		cout << "3. Print Persons Family" << endl;
		cout << "4. Print All Familys" << endl;
		cout << "5. Print all Roots" << endl;
		cout << "6. Quit" << endl;
		string userChoiceString;
		cin >> userChoiceString;
		
		// Check user input
		if (userChoiceString == "1")	// Add person
		{
			// Get all of the user input to make a new person
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
			if (spouse == "none")		// Account for possible lower case input
				spouse = "None";
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
			Person *newPerson = new Person(name, mothersName, fathersName, spouse, gender);	// Make a new instance of person with the user input
			cout << "Does " << newPerson -> getFullName() << " have any siblings? "; 
			bool doneWithSiblings = false;
			while (!doneWithSiblings)			// Get user input for all siblings
			{
				cout << "If not enter \"No\", otherwise enter their full name, \"First Last\": ";
				string userInput;
				getline(cin, userInput);
				if (userInput == "No" || userInput == "no")				// Check if the person is done with siblings yet
				{
					doneWithSiblings = true;
				}
				else
				{
					cout << userInput << " is a sibling? Enter \"Yes \" or \"No\": ";
					string confirm;
					getline(cin, confirm);
					if (confirm == "Yes" || confirm == "yes")			// If the current input is a sibling
					{
						cout << userInput << " has been added! " << endl;		// Add that sibling to the new persons sibList
						Person *newSib = new Person(userInput, myFamilyTree);
						newSib -> addSibling(newPerson);
						newPerson -> addSibling(newSib);
					}
					else
						cout << userInput << " has not been added as a sibling." << endl;
					cout << "Does " << newPerson -> getFullName() << " have any more siblings? ";
				}
			}
			cout << "Does " << newPerson -> getFullName() << " have any children? "; 
			bool doneWithChildren = false;
			while (!doneWithChildren)
			{
				cout << "If not enter \"No\", otherwise enter their full name, \"First Last\": ";
				string userInput;
				getline(cin, userInput);
				if (userInput == "No" || userInput == "no")				// Check if the person is done with children yet
				{
					doneWithChildren = true;
				}
				else
				{
					cout << userInput << " is a child? Enter \"Yes \" or \"No\": ";
					string confirm;
					getline(cin, confirm);
					if (confirm == "Yes" || confirm == "yes")				// If the current input is a child
					{
						cout << userInput << " has been added!" << endl;		// Add the child to the new persons childList
						Person *newChild = new Person(userInput, myFamilyTree);
						newPerson -> addChild(newChild);
					}
					else
						cout << userInput << " has not been added as a child" << endl;
					cout << "Does " << newPerson -> getFullName() << " have any more children?";
				}
			}
			myFamilyTree -> addToTree(newPerson);						// Add the new person to the tree
		}
		else if (userChoiceString == "2")	// Print Person information
		{
			cout << "What is the persons full name(\"First Last)\"?:" << endl;
			cin.ignore();
			string name;				// Get user input
			getline(cin, name);		
			Person *person = myFamilyTree -> findPerson(name); 	
			if (person != NULL)
			{
				person -> printInformation();	// Print persons information
			}
		}
		else if (userChoiceString == "3")	// Print persons family
		{
			cout << "What is the persons full name(\"First Last)\"?:" << endl;
			cin.ignore();
			string name;		// Get user input
			getline(cin, name);
			Person *person = myFamilyTree -> findPerson(name);
			if (person != NULL)
			{
				myFamilyTree -> printPersonsFamily(person -> getRoot());		// Print persons family
			}
			else
				cout << "This person not found" << endl;
		}
		else if (userChoiceString == "4")	// Print all families
		{
			myFamilyTree -> printAllFamilies();
		}
		else if (userChoiceString == "5")	// Print all family roots
		{
			myFamilyTree -> printAllRoots();
		}
		else if (userChoiceString == "6")	// Quit
		{
			cout << "Goodbye!" << endl; 
			done = true;
		}
	}
	return 0;
}
