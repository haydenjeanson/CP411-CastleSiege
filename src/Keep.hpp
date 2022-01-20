#ifndef KEEP_H
#define KEEP_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class Keep: public Shape {

protected:
	GLfloat vertex[8][3];
	GLint face[6][4];

	GLfloat faceColor[6][3];
	GLfloat faceNormal[6][3];
	GLfloat vertexColor[8][3];
	GLfloat vertexNormal[8][3];

public:
	Keep();
	void draw();
	void drawFace(int);

	bool isFrontface(int faceindex, Camera camera);
	GLfloat r, g, b;
};

#endif
