

#ifndef CASTLEDOOR_HPP_
#define CASTLEDOOR_HPP_

#include <GL/glut.h>

#include "MiniWallOne.hpp"
#include "MiniWallTwo.hpp"
#include "Battlement.hpp"

class CastleDoor: public Shape {

protected:
	MiniWallOne* leftWall;
	MiniWallOne* rightWall;
	MiniWallTwo* topWall;
	Battlement* b1;
	Battlement* b2;
	Battlement* b3;
	Battlement* b4;
	Battlement* b5;

public:
	~CastleDoor();
	CastleDoor();
	void draw();
};

#endif /* CASTLEDOOR_HPP_ */
