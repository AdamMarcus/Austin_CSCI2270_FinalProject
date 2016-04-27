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
		std::vector<Person*> sibList;		// A list for siblings
		std::vector<Person*> childList;		// A list for children
		
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
		void printInformation();		// Print personal information
		void setVisited();
		void setFamily(FamilyTree*);
		void setVisited(bool);
		void setFatherOrMother(int);
		void setSpouse(Person*);
		void setRoot(Person*);
		bool getVisited();
		Person *getBiologicalFather();
		Person *getBiologicalMother();
		Person *getSpouse();
		Person *getRoot();
		int getFatherOrMother();
		std::string getFullName();
		FamilyTree *getFamily();
    private:
		int fatherOrMother = -1;			// 0 indicates father, 1 indicates mother
		bool visited = false;				// Indicates if visited for breadth first searching
		std::string fullName = "Unknown";
		Person* root = NULL;				// Holds the root of a persons family
		FamilyTree *family;	
		Person *biologicalFather = NULL;	// Pointer to persons father
		Person *biologicalMother = NULL;	// Pointer to persons mother
		Person *spouse = NULL;				// Pointer to persons spouse
};

#endif
