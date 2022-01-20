#include "Castle.hpp"
#include <stdio.h>

Castle::Castle() {
	k1 = new CastleKeep();
	w1 = new CastleDoor();
	w1->translate(0, 7.5, 0);
	w2 = new CastleWall();
	w2->translate(0, -7.5, 0);
	w3 = new CastleWall();
	w3->translate(3.5, 9.5, 0);
	w3->rotate(0, 0, 1, -45);
	w4 = new CastleWall();
	w4->translate(3.5, -9.5, 0);
	w4->rotate(0, 0, 1, 45);
	w5 = new CastleWall();
	w5->translate(-3.5, 9.5, 0);
	w5->rotate(0, 0, 1, 45);
	w6 = new CastleWall();
	w6->translate(-3.5, -9.5, 0);
	w6->rotate(0, 0, 1, -45);
	t1 = new CastleTower();
	t1->translate(6, 7.5, 0);
	t2 = new CastleTower();
	t2->translate(6, -7.5, 0);
	t3 = new CastleTower();
	t3->translate(-6, 7.5, 0);
	t4 = new CastleTower();
	t4->translate(-6, -7.5, 0);
	t5 = new CastleTower();
	t5->translate(13, 0, 0);
	t6 = new CastleTower();
	t6->translate(-13, 0, 0);
}

Castle::~Castle() {
	delete k1;
	delete w1;
	delete w2;
	delete w3;
	delete w4;
	delete w5;
	delete w6;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;
	delete t6;
}

void Castle::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	k1->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	w1->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	w2->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	w3->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	w4->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	w5->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	w6->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	t1->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	t2->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	t3->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	t4->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	t5->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	t6->draw();
	glPopMatrix();
}
