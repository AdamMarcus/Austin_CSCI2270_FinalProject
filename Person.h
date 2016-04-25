/*
	Adam Austin
	4/22/2016
	TA: Quesada
*/

#ifndef _PERSON_H
#define _PERSON_H

#include "FamilyTree.h"
#include <iostream>
#include <vector>

class FamilyTree;

class Person
{
    public:
		std::vector<Person*> sibList;
		std::vector<Person*> childList;
		
		Person();
		Person(std::string, FamilyTree*);
		Person(std::string, std::string, std::string, FamilyTree*);
		~Person();
		void setBiologicalFather(Person*);
		void setBiologicalMother(Person*);
		void addSibling(Person*);
		void addChild(Person*);
		void setVisited();
		void setFamily(FamilyTree*);
		bool getVisited();
		Person *getBiologicalFather();
		Person *getBiologicalMother();
		std::string getFullName();
		FamilyTree *getFamily();
    private:
		bool visited = false;
		std::string fullName;
		FamilyTree *family;
		Person *biologicalFather = NULL;
		Person *biologicalMother = NULL;
};

#endif
