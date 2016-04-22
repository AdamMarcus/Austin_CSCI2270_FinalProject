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
		~Person();
		void setBiologicalFather(Person *);
		void setBiologicalMother(Person *);
		void addSibling(Person *);
		void addChild(Person *);
		Person *getBiologicalFather();
		Person *getBiologicalMother();
    private:
		std::vector<Person *> siblings;
		std::vector<Person *> children;
		Person *biologicalFather = NULL;
		Person *biologicalMother = NULL;
};

#endif
