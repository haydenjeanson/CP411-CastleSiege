
#ifndef HEAD_HPP_
#define HEAD_HPP_

#include <windows.h>
#include <GL/glut.h>
#include "Shape.hpp"

#include "Camera.hpp"

class Head: public Shape {

protected:
	GLdouble radius;
	GLint splices, stacks;
	GLfloat r, g, b;
	GLUquadric *quad;

public:
	Head();
	void draw();
};

#endif /* HEAD_HPP_ */
