#ifndef TOWER_HPP_
#define TOWER_HPP_

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class Tower: public Shape {

protected:
	GLfloat radius;
	GLfloat height;

	GLfloat r, g, b;

	GLfloat pi;

public:
	Tower();
	void draw();
};

#endif /* TOWER_HPP_ */
