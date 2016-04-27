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
		Person(std::string);
		Person(std::string, FamilyTree*);
		Person(std::string, std::string, std::string, FamilyTree*);
		Person(std::string, std::string, std::string, std::string, std::string);
		~Person();
		void setBiologicalFather(Person*);
		void setBiologicalMother(Person*);
		void addSibling(Person*);
		void addChild(Person*);
		void printInformation();
		void setVisited();
		void setFamily(FamilyTree*);
		void setVisited(bool);
		void setFatherOrMother(int);
		void setSpouse(Person*);
		bool getVisited();
		Person *getBiologicalFather();
		Person *getBiologicalMother();
		Person *getSpouse();
		int getFatherOrMother();
		std::string getFullName();
		FamilyTree *getFamily();
    private:
		int fatherOrMother = -1;
		bool visited = false;
		std::string fullName = "Unknown";
		FamilyTree *family;
		Person *biologicalFather = NULL;
		Person *biologicalMother = NULL;
		Person *spouse = NULL;
};

#endif
