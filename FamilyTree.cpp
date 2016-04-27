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
	cout << "In findPerson searching for " << _name << endl;
	resetVisited();
	Person *personToReturn = NULL;
	queue<Person*> personQueue;
	bool found = false;
	if (rootList.size() <= 0)
		found = true;
	for (int i = 0; i < rootList.size(); i++)
	{
		cout << "Pushing " << rootList[i] -> getFullName() << " to queue. (rootList)" << endl;
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
				cout << currentPerson -> getFullName() << " has been found." << endl;
				personToReturn = currentPerson;
				found = true;
			}
			if (currentPerson -> getBiologicalFather() -> getVisited() != true)
				personQueue.push(currentPerson -> getBiologicalFather());
			if (currentPerson -> getBiologicalMother() -> getVisited() != true)
				personQueue.push(currentPerson -> getBiologicalMother());
			if (currentPerson -> getSpouse() != NULL && currentPerson -> getSpouse() -> getVisited() != true)
				personQueue.push(currentPerson -> getSpouse());
			for (int i = 0; i < currentPerson -> sibList.size(); i++)
			{
				if (currentPerson -> sibList[i] -> getVisited() != true)
				{
					cout << "Pushing " << currentPerson -> sibList[i] -> getFullName() << " to queue." << endl;
					personQueue.push(currentPerson -> sibList[i]);
				}
			}
			for (int i = 0; i < currentPerson -> childList.size(); i++)
			{
				if (currentPerson -> childList[i] -> getVisited() != true)
				{
					cout << "Pushing " << currentPerson -> childList[i] -> getFullName() << " to queue." << endl;
					personQueue.push(currentPerson -> childList[i]);
				}
			}
			currentPerson -> setVisited(true);
		}
	}
	if (personToReturn == NULL)
		cout << "This person not found" << endl;
	else
		cout << "Leaving findPerson, " << personToReturn -> getFullName() << " found."<< endl;
	return personToReturn;
}

Person *FamilyTree::getUnknownPerson()
{
	return unknownPerson;
}

void FamilyTree::addToTree(Person* _person)
{
	cout << "in addToTree" << endl;
	personList.push_back(_person);
	bool addAsRoot = true;
	addAsRoot = searchForExistingMother(_person);
	if (addAsRoot)
		addAsRoot = searchForExistingFather(_person);
	else
		searchForExistingFather(_person);
	if (addAsRoot)
		addAsRoot = searchForExistingSiblings(_person);
	else
		searchForExistingSiblings(_person);
	if (addAsRoot)
		addAsRoot = searchForSpouse(_person);
	else
		searchForSpouse(_person);
	searchForExistingChildren(_person);
		
	if (addAsRoot)
	{
		cout << "adding " << _person -> getFullName() << " as a root" << endl;
		rootList.push_back(_person);
		_person -> setRoot(_person);
	}
}

bool FamilyTree::searchForExistingMother(Person *_person)
{
	cout << "in searchForExistingMother" << endl;
	bool addAsRoot = true;
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
			mother -> addChild(_person);
			_person -> setBiologicalMother(mother);
			_person -> setRoot(mother -> getRoot());
			addAsRoot = false;
		}
	}
	else
	{
		_person -> setBiologicalMother(unknownPerson);
	}
	return addAsRoot;
}

bool FamilyTree::searchForExistingFather(Person *_person)
{
	cout << "in searchForExistingFather" << endl;
	bool addAsRoot = true;
	if (_person -> getBiologicalFather() -> getFullName()  != "Unknown")
	{
		Person *father = findPerson(_person -> getBiologicalFather() -> getFullName());
		if (father != NULL)
		{
			for (int i = 0; i < father -> childList.size(); i++)
			{
				if (father -> childList[i] -> getFullName() == _person -> getFullName())
					father -> childList.erase(father -> childList.begin() + i - 1);
			}
			father -> addChild(_person);
			_person -> setBiologicalFather(father);
			_person -> setRoot(father -> getRoot());
			addAsRoot = false;
		}
	}
	else
	{
		_person -> setBiologicalFather(unknownPerson);
	}
	return addAsRoot;
}

bool FamilyTree::searchForSpouse(Person *_person)
{
	cout << "in searchForSpouse" << endl;
	bool addAsRoot = true;
	if (_person -> getSpouse() != NULL && _person -> getSpouse() -> getFullName()  != "Unknown")
	{
		Person *spouse = findPerson(_person -> getSpouse() -> getFullName());
		if (spouse != NULL)
		{
			delete _person -> getSpouse();
			if (spouse -> getSpouse() != NULL)
				delete spouse -> getSpouse();
			spouse -> setSpouse(_person);
			_person -> setSpouse(spouse);
			_person -> setRoot(spouse -> getRoot());
			addAsRoot = false;
		}
	}
	else if (_person -> getSpouse() != NULL)
	{
		_person -> setSpouse(unknownPerson);
	}
	return addAsRoot;
}


bool FamilyTree::searchForExistingSiblings(Person* _person)
{
	cout << "In searchForExistingSiblings" << endl;
	bool addAsRoot = true;												// Value to return
	int destination = _person -> sibList.size();						// Set the destination before the loop so it doesnt increase while looping
	for (int i = 0; i < destination; i++)								// For each sibbling to current person
	{
		cout << "flag 1" << endl;
		Person *sib = findPerson(_person -> sibList[i] -> getFullName());		// find the sibling using the findPerson method
		if (sib != NULL)													// If a person was found...
		{
			for (int j = 0; j < sib -> sibList.size(); j++)			// For each sibling to the person found...
			{
				cout << "flag 2" << endl;
				if (sib -> sibList[j] -> getFullName() == _person -> getFullName())		// If the sibling to the person found is the current person, 
				{
					cout << "erasing " << sib -> sibList[j] -> getFullName() << endl;
					sib -> sibList.erase(sib -> sibList.begin() + j - 1);				// Erase that person node from the list
				}
			}
			sib -> addSibling(_person);												// Add the real person node to the sibling list
			cout << "erasing " << _person -> sibList[i] -> getFullName() << endl;
			_person -> sibList.erase(_person -> sibList.begin() + i - 1);
			_person -> addSibling(sib);
			_person -> setRoot(sib -> getRoot());												// Add the current found sibling to the current persons list
			addAsRoot = false;														// Set the return value to false to indicate someone in that tree already existed
		}
	}
	return addAsRoot;
}

bool FamilyTree::searchForExistingChildren(Person* _person)
{
	cout << "in searchForExistingChildren" << endl;
	bool addAsRoot = true;
	for (int i = 0; i < _person -> childList.size(); i++)
	{
		Person *child = findPerson(_person -> childList[i] -> getFullName());
		if (child != NULL)
		{
			for (int j = 0; j < child -> childList.size(); j++)
			{
				if (child -> childList[j] -> getFullName() == _person -> getFullName())
				{
					cout << "erasing " << child -> childList[j] -> getFullName() << endl;
					child -> childList.erase(child -> childList.begin() + j - 1);
				}
			}
			if (_person -> getFatherOrMother() == 0)
				child -> setBiologicalFather(_person);
			else if (_person -> getFatherOrMother() == 1)
				child -> setBiologicalMother(_person);
			cout << "erasing " << _person -> childList[i] -> getFullName() << endl;
			_person -> childList.erase(_person -> childList.begin() + i - 1);
			_person -> addChild(child);
			child -> setRoot(_person -> getRoot());
			removeFromRootList(child);
		}
	}
	return addAsRoot;
}

int FamilyTree::getRootListSize()
{
	return rootList.size();
}

void FamilyTree::resetVisited()
{
	cout << "reseting visited" << endl;
	for (int i = 0; i < personList.size(); i++)
		personList[i] -> setVisited(false);
}

void FamilyTree::setUnknownPerson(Person *_person)
{
	unknownPerson = _person;
}

void FamilyTree::removeFromRootList(Person *_person)
{
	bool done = false;
	for (int i = 0; !done && i < rootList.size(); i++)
	{
		if (rootList[i] == _person)
		{
			rootList.erase(rootList.begin() + i - 1);
			done = true;
		}
	}
}

void FamilyTree::printAllRoots()
{
	if (rootList.size() == 0)
		cout << "No Roots" << endl;
	else
	{
		cout << "Roots";
		for (int i = 0; i < rootList.size(); i++)
			cout << ", " << rootList[i] -> getFullName();
		cout << endl;
	}
}

void FamilyTree::printAllFamilies()
{
	for (int i = 0; i < rootList.size(); i++)
		printPersonsFamily(rootList[i]);
}

void FamilyTree::printPersonsFamily(Person *_person)
{
	if (_person -> getBiologicalFather() != NULL)
		_person -> getBiologicalFather() -> printInformation();
	if (_person -> getBiologicalMother() != NULL)
		_person -> getBiologicalMother() -> printInformation();
	
	queue<Person*> personQueue;
	personQueue.push(_person);
	while (personQueue.empty() != true)
	{
		Person *currentPerson = personQueue.front();
		personQueue.pop();
		if (currentPerson -> getVisited() != true)
		{
			currentPerson -> printInformation();
			currentPerson -> setVisited(true);
		}
		
		if (currentPerson -> getSpouse() != NULL)
			personQueue.push(currentPerson -> getSpouse());
		for (int i = 0; i < currentPerson -> sibList.size(); i++)
		{
			if (currentPerson -> sibList[i] -> getVisited() != true)
				personQueue.push(currentPerson -> sibList[i]);
		}
		for (int i = 0; i < currentPerson -> childList.size(); i++)
		{
			if (currentPerson -> childList[i] -> getVisited() != true)
				personQueue.push(currentPerson -> childList[i]);
		}
	}
}
