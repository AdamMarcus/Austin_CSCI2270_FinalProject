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
    private:
		std::vector<Person*> rootList;
		Person* findPerson(std::string);
};

#endif

