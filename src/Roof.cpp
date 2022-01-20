#include "Roof.hpp"
#include "Camera.hpp"
#include <stdio.h>

Roof::Roof() {
	r = 0.3;
	g = 0;
	b = 0;
}

void Roof::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);

	glBegin(GL_TRIANGLES);
	for (int i=0; i<360; i+=5) {
		glColor3f(r, g, b);
		glVertex3f(0, 0, 2);
		glColor3f(r, g, b);
		glVertex3f(cos(i), sin(i), 0);
		glColor3f(r, g, b);
		glVertex3f(cos(i+5), sin(i+5), 0);
	}
	glEnd();

	glRotated(90, 1, 0, 0);
	glBegin(GL_TRIANGLES);
	for (int j=0; j<360; j+=5) {
		glColor3f(r, g, b);
		glVertex3f(0, 0, 0);
		glColor3f(r, g, b);
		glVertex3f(cos(j), 0, sin(j));
		glColor3f(r, g, b);
		glVertex3f(cos(j+5), 0, sin(j+5));
	}
	glEnd();

	glPopMatrix();
}




