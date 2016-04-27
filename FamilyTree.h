/*
	Adam Austin
	4/22/2016
	TA: Quesada
*/

#ifndef _FAMILYTREE_H
#define _FAMILYTREE_H

#include "Person.h"
#include <iostream>
#include <vector>

class Person;

class FamilyTree
{
    public:    
		FamilyTree();
		~FamilyTree();
		Person* findPerson(std::string);
		bool searchForExistingMother(Person*);
		bool searchForExistingFather(Person*);
		bool searchForExistingSiblings(Person*);
		bool searchForExistingChildren(Person*);
		int getRootListSize();
		Person* getUnknownPerson();
		void addToTree(Person*);
		void resetVisited();
		void setUnknownPerson(Person*);
		void removeFromRootList(Person*);
    private:
		Person *unknownPerson;// = new Person("Unknown");
		std::vector<Person*> rootList;
		std::vector<Person*> personList;
};

#endif

