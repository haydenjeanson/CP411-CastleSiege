#ifndef ROOF_HPP_
#define ROOF_HPP_

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

#include "Camera.hpp"

class Roof: public Shape {

protected:
	GLfloat r, g, b;

public:
	Roof();
	void draw();
};

#endif /* ROOF_HPP_ */
