#include "CastleDoor.hpp"
#include <stdio.h>

CastleDoor::CastleDoor() {
	leftWall = new MiniWallOne;
	leftWall->translate(-3, 0, 0);
	rightWall = new MiniWallOne;
	rightWall->translate(3, 0, 0);
	topWall = new MiniWallTwo;
	b1 = new Battlement();
	b1->setParentMC(&mc);
	b2 = new Battlement();
	b2->setParentMC(&mc);
	b2->translate(2.0, 0, 0);
	b3 = new Battlement();
	b3->setParentMC(&mc);
	b3->translate(4.0, 0, 0);
	b4 = new Battlement();
	b4->setParentMC(&mc);
	b4->translate(-2.0, 0, 0);
	b5 = new Battlement();
	b5->setParentMC(&mc);
	b5->translate(-4.0, 0, 0);
}

CastleDoor::~CastleDoor() {
	delete leftWall;
	delete rightWall;
	delete topWall;
	delete b1;
	delete b2;
	delete b3;
	delete b4;
	delete b5;
}

void CastleDoor::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	leftWall->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	rightWall->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	topWall->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b1->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b2->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b3->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b4->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b5->draw();
	glPopMatrix();
}
