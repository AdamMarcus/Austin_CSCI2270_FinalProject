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
	for (int i = 0; i < personList.size(); i++)
		delete personList[i];
}

Person* FamilyTree::findPerson(string _name)
{	
	Person *personToReturn = NULL;					// Make a person to hold the person to return when found
	bool found = false;								// Boolean to indicate if person has been found
	for (int i = 0; i < personList.size(); i++)		// For each person in the tree
	{
		if (personList[i] -> getFullName() == _name)// If the persons name matches the name looking for
		{
			personToReturn = personList[i];			// Set the return person to that person
			found = true;							// Set found = true
		}
	}
	return personToReturn;
		
}

Person *FamilyTree::getUnknownPerson()
{
	return unknownPerson;
}

void FamilyTree::addToTree(Person* _person)
{
	//cout << "in addToTree" << endl;
	personList.push_back(_person);							// Add the new person to the person list
	bool addAsRoot = true;									// Make bool to store weather or not the new person is the root of their family
	addAsRoot = searchForExistingMother(_person);			// Search for an existing mother, if found return false
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
		
	if (addAsRoot)							// If no family members were found as existing
	{
		//cout << "adding " << _person -> getFullName() << " as a root" << endl;
		rootList.push_back(_person);		// Add the new person as the root of their family
		_person -> setRoot(_person);		// Set the persons root to themself
	}
}

bool FamilyTree::searchForExistingMother(Person *_person)
{
	//cout << "in searchForExistingMother" << endl;
	bool addAsRoot = true;																// Bool to store if person found
	if (_person -> getBiologicalMother() -> getFullName()  != "Unknown")				// If persons mother is not unknown
	{
		Person *mother = findPerson(_person -> getBiologicalMother() -> getFullName());	// search for their mother
		if (mother != NULL)																// if their mother was found
		{
			for (int i = 0; i < mother -> childList.size(); i++)							// For each child to the found mother
			{
				if (mother -> childList[i] -> getFullName() == _person -> getFullName())// If the current child is the _person
					mother -> childList.erase(mother -> childList.begin() + i - 1);		// Delete the temp child node from the mothers child list
			}
			mother -> addChild(_person);												// Link the mother to the real child node
			_person -> setBiologicalMother(mother);										// Link _person to the mother
			_person -> setRoot(mother -> getRoot());									// Set the _person's root to the mothers root
			addAsRoot = false;															// Do not add the person as a root
		}
	}
	else 					// If the mother was unknown
	{
		_person -> setBiologicalMother(unknownPerson);									// Set mother as unknown
	}
	return addAsRoot;
}

bool FamilyTree::searchForExistingFather(Person *_person)
{
	//cout << "in searchForExistingFather" << endl;
	bool addAsRoot = true;																// Bool to store if person found
	if (_person -> getBiologicalFather() -> getFullName()  != "Unknown")				// If persons father is not unknown
	{
		Person *father = findPerson(_person -> getBiologicalFather() -> getFullName());// search for their father
		if (father != NULL)																// if their father was found
		{
			for (int i = 0; i < father -> childList.size(); i++)							// For each child to the found father
			{
				if (father -> childList[i] -> getFullName() == _person -> getFullName())// If the current child is the _person
					father -> childList.erase(father -> childList.begin() + i - 1);		// Delete the temp child node from the fathers child list
			}
			father -> addChild(_person);												// Link the father to the real child node
			_person -> setBiologicalFather(father);										// Link _person to the mother
			_person -> setRoot(father -> getRoot());									// Set the _person's root to the fathers root
			addAsRoot = false;															// Do not add the person as a root
		}
	}
	else 					// If the father was unknown
	{
		_person -> setBiologicalFather(unknownPerson);							// Set father as unknown
	}
	return addAsRoot;
}

bool FamilyTree::searchForSpouse(Person *_person)
{
	//cout << "in searchForSpouse" << endl;
	bool addAsRoot = true;
	if (_person -> getSpouse() != NULL && _person -> getSpouse() -> getFullName()  != "Unknown")	// If spouse is neither Unknown or None
	{
		Person *spouse = findPerson(_person -> getSpouse() -> getFullName());	// Search for the spouse
		if (spouse != NULL)														// If found
		{
			delete _person -> getSpouse();										// Delete _person's temp spouse node
			if (spouse -> getSpouse() != NULL)									// If the found spouse had a spouse
				delete spouse -> getSpouse();									// Delete their spouse node
			spouse -> setSpouse(_person);										// set the spouses spouse to _person
			_person -> setSpouse(spouse);										// Set persons spouse to spouse
			_person -> setRoot(spouse -> getRoot());							// Set the persons root to spouses root
			addAsRoot = false;													// Do not add person as root
		}
	}
	else if (_person -> getSpouse() != NULL)									// If the spouse was unknown
	{
		_person -> setSpouse(unknownPerson);									// Set persons spouse to the Unkown person
	}
	return addAsRoot;
}


bool FamilyTree::searchForExistingSiblings(Person* _person)
{
	//cout << "In searchForExistingSiblings" << endl;
	bool addAsRoot = true;												// Value to return
	int destination = _person -> sibList.size();						// Set the destination before the loop so it doesnt increase while looping
	for (int i = 0; i < destination; i++)								// For each sibbling to current person
	{
		//cout << "flag 1" << endl;
		Person *sib = findPerson(_person -> sibList[i] -> getFullName());		// find the sibling using the findPerson method
		if (sib != NULL)													// If a person was found...
		{
			for (int j = 0; j < sib -> sibList.size(); j++)			// For each sibling to the person found...
			{
				//cout << "flag 2" << endl;
				if (sib -> sibList[j] -> getFullName() == _person -> getFullName())		// If the sibling to the person found is the current person, 
				{
					//cout << "erasing " << sib -> sibList[j] -> getFullName() << endl;
					sib -> sibList.erase(sib -> sibList.begin() + j - 1);				// Erase that person node from the list
				}
			}
			sib -> addSibling(_person);												// Add the real person node to the sibling list
			//cout << "erasing " << _person -> sibList[i] -> getFullName() << endl;
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
	//cout << "in searchForExistingChildren" << endl;
	bool addAsRoot = true;
	for (int i = 0; i < _person -> childList.size(); i++)									// For each child
	{
		Person *child = findPerson(_person -> childList[i] -> getFullName());				// Search for the child
		if (child != NULL)																	// If the child was found
		{
			/*for (int j = 0; j < child -> childList.size(); j++)
			{
				if (child -> childList[j] -> getFullName() == _person -> getFullName())
				{
					cout << "erasing " << child -> childList[j] -> getFullName() << endl;
					child -> childList.erase(child -> childList.begin() + j - 1);
				}
			}*/
			if (_person -> getFatherOrMother() == 0)		// If the person is a father
				child -> setBiologicalFather(_person);		// Set that person as childs biological father
			else if (_person -> getFatherOrMother() == 1)	// Else the person is a mother
				child -> setBiologicalMother(_person);		// Set that person as childs biological mother
			//cout << "erasing " << _person -> childList[i] -> getFullName() << endl;		// Delete the t
			_person -> childList.erase(_person -> childList.begin() + i - 1);			// Erase the temporary child node
			_person -> addChild(child);													// Add the real child as a child to person
			child -> setRoot(_person -> getRoot());										// Set the childs root to their parents root
			removeFromRootList(child);													// remove the child from the root list
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
	//cout << "reseting visited" << endl;
	for (int i = 0; i < personList.size(); i++)							// For each person in the family tree (Unknown person is not in the family tree and will remain unchanged
		personList[i] -> setVisited(false);								// Set that persons visited to false
}

void FamilyTree::setUnknownPerson(Person *_person)
{
	unknownPerson = _person;
}

void FamilyTree::removeFromRootList(Person *_person)
{
	bool done = false;									
	for (int i = 0; !done && i < rootList.size(); i++)					// While not done, for each person in root list
	{
		if (rootList[i] == _person)										// If the person == _person
		{
			rootList.erase(rootList.begin() + i - 1);					// Erase that node from the root list
			done = true;												// Set done to true
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
		for (int i = 0; i < rootList.size(); i++)						// For each root in the root list
			cout << ", " << rootList[i] -> getFullName();				// Print the roots name
		cout << endl;
	}
}

void FamilyTree::printAllFamilies()
{
	resetVisited();
	for (int i = 0; i < rootList.size(); i++)							// For every root in root list
	{
		cout << "Family #" << i << endl;
		printPersonsFamily(rootList[i]);								// Print that roots family
	}
}

void FamilyTree::printPersonsFamily(Person *_person)
{
	//cout << 
	if (_person -> getBiologicalFather() != NULL)						// Roots will have temp parent nodes, if they have a temp father
		_person -> getBiologicalFather() -> printInformation();			// Print the temp father
	if (_person -> getBiologicalMother() != NULL)						// If they have a temp mother
		_person -> getBiologicalMother() -> printInformation();			// Print the temp mother
	
	queue<Person*> personQueue;											// Queue for breadth first searching
	personQueue.push(_person);											// Push the current person to queue
	while (personQueue.empty() != true)
	{
		Person *currentPerson = personQueue.front();					// Get next person in queue
		personQueue.pop();												// Delete them from queue
		if (currentPerson -> getVisited() != true)						// If the person has not been visited
		{
			currentPerson -> printInformation();						// Print the current persons information
			currentPerson -> setVisited(true);							// Set their visited to true
		}
		
		if (currentPerson -> getSpouse() != NULL)						// If the person has a spouse or unknown
			personQueue.push(currentPerson -> getSpouse());				// Enqueue their spouse
		for (int i = 0; i < currentPerson -> sibList.size(); i++)		// For each sibling in the persons sibList
		{
			if (currentPerson -> sibList[i] -> getVisited() != true)	// If the sib is unvisited...
				personQueue.push(currentPerson -> sibList[i]);			// Enqueue that sib
		}
		for (int i = 0; i < currentPerson -> childList.size(); i++)		// For each child in persons childList
		{
			if (currentPerson -> childList[i] -> getVisited() != true) 	// If the current child is unvisited
				personQueue.push(currentPerson -> childList[i]);		// Enqueue that child
		}
	}
}
