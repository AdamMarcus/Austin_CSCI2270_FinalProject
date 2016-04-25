/*
	Adam Austin
	4/22/2016
	TA: Quesada
*/

#include "Person.h"
#include "FamilyTree.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

FamilyTree::FamilyTree()
{
	
}

FamilyTree::~FamilyTree()
{
	
}

Person* FamilyTree::findPerson(string _name)
{
	Person *personToReturn = NULL;
	queue<Person*> personQueue;
	bool found = false;
	if (rootList.size() <= 0)
		found = true;
	for (int i = 0; i < rootList.size(); i++)
	{
		personQueue.push(rootList[i]);
	}
	while (!found && !personQueue.empty())
	{
		Person *currentPerson = personQueue.front();
		personQueue.pop();
		if (currentPerson -> getVisited() == false)
		{
			if (currentPerson -> getFullName() == _name)
			{
				personToReturn = currentPerson;
				found = true;
			}
			personQueue.push(currentPerson -> getBiologicalFather());
			personQueue.push(currentPerson -> getBiologicalMother());
			for (int i = 0; i < currentPerson -> sibList.size(); i++)
				personQueue.push(currentPerson -> sibList[i]);
			for (int i = 0; i < currentPerson -> childList.size(); i++)
				personQueue.push(currentPerson -> childList[i]);
			}
	}
	return personToReturn;
}

void FamilyTree::addToTree(Person* _person)
{
	if (_person -> getBiologicalMother() -> getFullName()  != "Unknown")
	{
		Person *mother = findPerson(_person -> getBiologicalMother() -> getFullName());
		if (mother != NULL)
		{
			for (int i = 0; i < mother -> childList.size(); i++)
			{
				if (mother -> childList[i] -> getFullName() == _person -> getFullName())
					mother -> childList.erase(mother -> childList.begin() + i - 1);
			}
			mother -> childList.push_back(_person);
			_person -> setBiologicalMother(mother);
			_person -> setFamily(mother -> getFamily());
		}
	}
	else if (_person -> getBiologicalFather() -> getFullName()  != "Unknown")
	{
		Person *father = findPerson(_person -> getBiologicalFather() -> getFullName());
		if (father != NULL)
		{
			for (int i = 0; i < father -> childList.size(); i++)
			{
				if (father -> childList[i] -> getFullName() == _person -> getFullName())
					father -> childList.erase(father -> childList.begin() + i - 1);
			}
			father -> childList.push_back(_person);
			_person -> setBiologicalFather(father);
		}
	}
	else
	{
		rootList.push_back(_person);
	}
	
	for (int i = 0; i < _person -> sibList.size(); i++)
	{
		if (findPerson(_person -> sibList[i] -> getFullName()) != NULL)
		{
			_person -> sibList.push_back(findPerson(_person -> sibList[i] -> getFullName()));
			_person -> sibList.erase(_person -> sibList.begin() + i - 1);
		}
	}
	
	for (int i = 0; i < _person -> childList.size(); i++)
	{
		if (findPerson(_person -> childList[i] -> getFullName()) != NULL)
		{
			_person -> childList.push_back(findPerson(_person -> childList[i] -> getFullName()));
			_person -> childList.erase(_person -> childList.begin() + i - 1);
		}
	}
}
