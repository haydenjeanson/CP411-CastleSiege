#include "CastleKeep.hpp"
#include <stdio.h>

CastleKeep::CastleKeep() {
	keep= new Keep();
	b1 = new Battlement();
	b1->translate(0, 1.5, 2.0);
	b2 = new Battlement();
	b2->translate(0, -1.5, 2.0);
	b3 = new Battlement();
	b3->translate(1.5, 0, 2.0);
	b4 = new Battlement();
	b4->translate(-1.5, 0, 2.0);
	b5 = new Battlement();
	b5->translate(1.5, 1.5, 2.0);
	b6 = new Battlement();
	b6->translate(1.5, -1.5, 2.0);
	b7 = new Battlement();
	b7->translate(-1.5, 1.5, 2.0);
	b8 = new Battlement();
	b8->translate(-1.5, -1.5, 2.0);

	r = 0.7;
	g = 0.8;
	b = 0.9;


	keep->r = r+0.1;
	keep->g = g+0.1;
	keep->b = b+0.1;
}

CastleKeep::~CastleKeep() {
	delete keep;
	delete b1;
	delete b2;
	delete b3;
	delete b4;
	delete b5;
	delete b6;
	delete b7;
	delete b8;
}

void CastleKeep::draw() {



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

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b6->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b7->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	b8->draw();
	glPopMatrix();


	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	keep->draw();
	glPopMatrix();
}
