/*
	Adam Austin
	4/22/2016
	TA: Quesada
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>

class Person
{
    public:
		Person();
		Person(std::string);
		~Person();
		void setBiologicalFather(Person *);
		void setBiologicalMother(Person *);
		void addSibling(Person *);
		void addChild(Person *);
		void addSibToStringList(std::string);
		void addChildToStringList(std::string);
		Person *getBiologicalFather();
		Person *getBiologicalMother();
    private:
		std::string fullName;
		std::vector<Person *> sibList;
		std::vector<Person *> childList;
		std::vector<std::string> sibStrings;
		std::vector<std::string> childStrings;
		Person *biologicalFather = NULL;
		Person *biologicalMother = NULL;
};

#endif
