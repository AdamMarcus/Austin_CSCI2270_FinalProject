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
		void addSibToStringList(std::string);
		void addChildToStringList(std::string);
		void setVisited();
		bool getVisited();
		Person *getBiologicalFather();
		Person *getBiologicalMother();
		std::string getFullName();
    private:
		bool visited = false;
		std::string fullName;
		FamilyTree *family;
		std::vector<std::string> sibStrings;
		std::vector<std::string> childStrings;
		Person *biologicalFather = NULL;
		Person *biologicalMother = NULL;
};

#endif
