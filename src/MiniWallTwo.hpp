#ifndef MINIWALLTWO_HPP_
#define MINIWALLTWO_HPP_

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class MiniWallTwo: public Shape {

protected:
	GLfloat vertex[8][3];
	GLint face[6][4];

	GLfloat faceColor[6][3];
	GLfloat faceNormal[6][3];
	GLfloat vertexColor[8][3];
	GLfloat vertexNormal[8][3];

	GLfloat r, g, b;

public:
MiniWallTwo();
void draw();
void drawFace(int);

bool isFrontface(int faceindex, Camera camera);
};

#endif /* MINIWALLTWO_HPP_ */
