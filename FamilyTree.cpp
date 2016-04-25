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
		if (currentPerson -> getFullName() == _name)
		{
			personToReturn = currentPerson;
			found = true;
		}
		else if (currentPerson -> getVisited() == false)
		{
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
	/*if (_person -> getBiologicalMother() != NULL)
	{
		Person *mother = findPerson(_person -> getBiologicalMother() -> name);
		bool found = false;
		for (int i = 0; !found && i < mother -> child
		
		mother -> childList.pushBack
	}
	else if (_person -> getBiologicalFather() != NULL)
	{
		Person *father = findPerson(_person -> getBiologicalFather());
	}*/
}
