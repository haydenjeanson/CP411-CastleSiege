

#ifndef SRC_CASTLEWALL_HPP_
#define SRC_CASTLEWALL_HPP_

#include <GL/glut.h>

#include "Wall.hpp"
#include "Battlement.hpp"

class CastleWall: public Shape{
protected:
	Wall* wall;
	Battlement* b1;
	Battlement* b2;
	Battlement* b3;
	Battlement* b4;
	Battlement* b5;

public:
	~CastleWall();
	CastleWall();
	void draw();
};

#endif /* SRC_CASTLEWALL_HPP_ */
