
#ifndef BODY_HPP_
#define BODY_HPP_

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class Body: public Shape {

protected:
	GLfloat radius;
	GLfloat height;

	GLfloat pi;

public:
	Body();
	void draw();
	GLfloat r, g, b;
};

#endif /* BODY_HPP_ */
