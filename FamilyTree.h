/*
Adam Austin
4/22/2016
TA: Quesada
*/

#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include "Person.h"
#include <iostream>
#include <vector>

class FamilyTree
{
    public:
		FamilyTree();
		~FamilyTree();
    private:
		Person *root;
		std::vector<Person *> familyList;
};

#endif

