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
		Person* findPerson(std::string);			// Find a person in the tree
		bool searchForExistingMother(Person*);		// Search for a persons possibly existing mother in the tree
		bool searchForExistingFather(Person*);		// Search for a persons possibly existing father in the tree
		bool searchForSpouse(Person*);				// Search for a persons possibly existing spouse in the tree
		bool searchForExistingSiblings(Person*);	// Search for a persons possibly existing siblings in the tree
		bool searchForExistingChildren(Person*);	// Search for a persons possibly existing children in the tree
		int getRootListSize();						// Return the currnet number of roots
		Person* getUnknownPerson();					// Return the "Unknown" person whos visited is always true
		void addToTree(Person*);					// Add a person node to the tree
		void resetVisited();						// Reset all persons visited fields in the tree to false
		void setUnknownPerson(Person*);				// set the "Unknown" person 
		void removeFromRootList(Person*);			// Remove a person from the root list
		void printAllRoots();						// Print all the roots
		void printAllFamilies();					// Print every family trees in the tree
		void printPersonsFamily(Person*);			// Print one persons family tree
    private:
		/* The "Unkown" person is not in the tree, and its visited is always NULL. 
		 * This allows it to be skiped during breadth first searching. This person should be used as a pointer for 
		 * family members who are Unknown, and therefore can hold the place of a spouse or parent, but will not be looked for during
		 * searching
		 */
		Person *unknownPerson;
		std::vector<Person*> rootList;			// A list of the oldest people in all current family trees
		std::vector<Person*> personList;		// A list of every person in the system to be reset during searching
};

#endif

