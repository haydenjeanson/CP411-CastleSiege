#include "Person.hpp"
#include <stdio.h>

Person::Person() {
	body = new Body();
	head = new Head();
	head->translate(0, 0, 0.8);
}

Person::~Person() {
	delete body;
	delete head;
}

void Person::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	body->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	head->draw();
	glPopMatrix();
}
