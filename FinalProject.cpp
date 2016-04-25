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
			Person *newPerson = new Person(name);
		}
		else if (userChoiceString == "2")
		{
			cout << "What is the persons full name(\"First Last)\"?:" << endl;
			cin.ignore();
			string name;
			getline(cin, name);
			Person *newPerson = new Person(name);
		}
		else if (userChoiceString == "5")
		{
			cout << "Goodbye!" << endl; 
			done = true;
		}
	}
	return 0;
}
