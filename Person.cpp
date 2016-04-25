/*
	Adam Austin
	4/22/2016
	TA: Quesada
*/

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person()
{
	
}

Person::Person(string _name, FamilyTree *_family)
{
	fullName = _name;
	family = _family;
}

Person::Person(string _fullName, string _mothersName, string _fathersName, FamilyTree *_family)
{
	fullName = _fullName;
	biologicalMother = new Person(_mothersName, _family);
	biologicalFather = new Person(_fathersName, _family);
	cout << "Does " << _fullName << " have any siblings?"; 
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
			cout << userInput << " is a sibling? Enter \"Yes \" or \"No\": ";
			string confirm;
			getline(cin, confirm);
			if (confirm == "Yes")
				addSibToStringList(userInput);
			else
				cout << userInput << " has not been added as a sibling" << endl;
			cout << "Does " << _fullName << " have any more siblings?";
		}
	}
}

Person::~Person()
{
	
}
		
void Person::setBiologicalFather(Person *_inputPerson)
{
	biologicalFather = _inputPerson;
}

void Person::setBiologicalMother(Person *_inputPerson)
{
	biologicalMother = _inputPerson;
}

void Person::addSibling(Person *_inputPerson)
{
	sibList.push_back(_inputPerson);
}

void Person::addChild(Person *_inputPerson)
{
	childList.push_back(_inputPerson);
}

void Person::addSibToStringList(string _name)
{
	sibStrings.push_back(_name);
}

void Person::addChildToStringList(string _name)
{
	childStrings.push_back(_name);
}

Person *Person::getBiologicalFather()
{
	return biologicalFather;
}

Person *Person::getBiologicalMother()
{
	return biologicalMother;
}

string Person::getFullName()
{
	return fullName;
}

bool Person::getVisited()
{
	return visited;
}
