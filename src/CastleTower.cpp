#include "CastleTower.hpp"
#include <stdio.h>

CastleTower::CastleTower() {
	tower = new Tower();
	roof = new Roof();
	roof->translate(0, 0, 4.0);
}

CastleTower::~CastleTower() {
	delete tower;
	delete roof;
}

void CastleTower::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	tower->draw();
	glPopMatrix();

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	roof->draw();
	glPopMatrix();
}


