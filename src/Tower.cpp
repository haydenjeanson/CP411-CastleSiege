#include "Tower.hpp"
#include "Camera.hpp"
#include <stdio.h>

Tower::Tower() {
	radius = 1.0;
	height = 4.0;
	r = 0.75;
	g = 0.75;
	b = 0.75;
	pi = 3.14159265359;
}

void Tower::draw() {
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angles = 0.1;

	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);

	glColor3f(r, g, b);
	glBegin(GL_QUAD_STRIP);

	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angles;
	}

	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	angle = 0.0;

	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angles;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();

	glPopMatrix();
}
