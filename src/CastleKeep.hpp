
#ifndef CASTLEKEEP_HPP_
#define CASTLEKEEP_HPP_

#include <GL/glut.h>

#include "Keep.hpp"
#include "Battlement.hpp"

class CastleKeep: public Shape {

protected:
	Keep* keep;
	Battlement* b1;
	Battlement* b2;
	Battlement* b3;
	Battlement* b4;
	Battlement* b5;
	Battlement* b6;
	Battlement* b7;
	Battlement* b8;

	GLfloat r, g, b;
public:
	~CastleKeep();
	CastleKeep();
	void draw();
};

#endif /* CASTLEKEEP_HPP_ */
