/*
 * guard.cpp
 *
 *  Created on: Dec 7, 2021
 *      Author: hayden
 */


#include "Guard.hpp"
#include <stdio.h>

Guard::Guard() {
	person = new Person();

	person->body->r = 0.3;
	person->body->g = 0;
	person->body->b = 0;
}

Guard::~Guard() {
	delete person;
}

void Guard::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	person->draw();
	glPopMatrix();
}
