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

Person::Person(string _name)
{
	fullName = _name;
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
}

Person::Person(string _fullName, string _mothersName, string _fathersName, string _spouseName, string _gender)
{
	fullName = _fullName;
	biologicalMother = new Person(_mothersName);
	biologicalFather = new Person(_fathersName);
	if (_spouseName != "None")
		spouse = new Person(_spouseName);		// If spouse name is none, leave spouse as NULL
	if (_gender == "m")							// Set the persons gender to determin if they would be a father or mother
		fatherOrMother = 0;
	else
		fatherOrMother = 1;
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

void Person::printInformation()			// Print all of the persons personal information
{
	cout << "=====================" << endl;
	cout << "Name: " << fullName << endl;
	if (biologicalMother != NULL)
		cout << "Mother: " << biologicalMother -> getFullName() << endl;
	if (biologicalFather != NULL)
		cout << "Father: " << biologicalFather -> getFullName() << endl;
	if (spouse != NULL)
		cout << "Spouse: " << spouse -> getFullName() << endl;
	else
		cout << "Spouse: None" << endl;
	cout << "Siblings";
	for (int i = 0; i < sibList.size(); i++)
	{
		cout << ", " << sibList[i] -> getFullName();
	}
	cout << endl;
	cout << "Children";
	for (int i = 0; i < childList.size(); i++)
	{
		cout << ", " << childList[i] -> getFullName();
	}
	cout << endl;
}

void Person::setFamily(FamilyTree *_family)
{
	family = _family;
}

void Person::setVisited(bool _visited)
{
	visited = _visited;
}

void Person::setFatherOrMother(int _fatherOrMother)
{
	fatherOrMother = _fatherOrMother;
}

void Person::setSpouse(Person *_person)
{
	spouse = _person;
}

void Person::setRoot(Person *_person)
{
	root = _person;
}

Person *Person::getBiologicalFather()
{
	return biologicalFather;
}

Person *Person::getBiologicalMother()
{
	return biologicalMother;
}

Person *Person::getSpouse()
{
	return spouse;
}

Person *Person::getRoot()
{
	return root;
}

string Person::getFullName()
{
	return fullName;
}

bool Person::getVisited()
{
	return visited;
}

int Person::getFatherOrMother()
{
	return fatherOrMother;
}

FamilyTree *Person::getFamily()
{
	return family;
}
