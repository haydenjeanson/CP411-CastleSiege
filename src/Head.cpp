#include "Head.hpp"
#include "Camera.hpp"
#include <stdio.h>

Head::Head() {
	radius = 0.22;
	splices = 50;
	stacks = 50;
	r = 0.9;
	g = 0.7;
	b = 0.5;
	quad = gluNewQuadric();
}

void Head::draw() {
	glPushMatrix();
	ctmMultiply();

	glColor3f(r, g, b);
	glutSolidSphere(radius,splices,stacks);

	glPopMatrix();
}


