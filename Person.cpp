/*
Adam Austin
4/22/2016
TA: Quesada
*/

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person()
{
	
}

Person::~Person()
{
	
}
		
void Person::setBiologicalFather(Person *_inputPerson)
{
	biologicalFather = _inputPerson;
}

void Person::setBiologicalMother(Person *_inputPerson)
{
	biologicalMother = _inputPerson;
}

void Person::addSibling(Person *_inputPerson)
{
	siblings.push_back(_inputPerson);
}

void Person::addChild(Person *_inputPerson)
{
	children.push_back(_inputPerson);
}

Person *Person::getBiologicalFather()
{
	return biologicalFather;
}

Person *Person::getBiologicalMother()
{
	return biologicalMother;
}
