

#ifndef CASTLE_HPP_
#define CASTLE_HPP_

#include <GL/glut.h>

#include "CastleKeep.hpp"
#include "CastleTower.hpp"
#include "CastleWall.hpp"
#include "CastleDoor.hpp"

class Castle: public Shape {
protected:
	CastleKeep* k1;
	CastleDoor* w1;
	CastleWall* w2;
	CastleWall* w3;
	CastleWall* w4;
	CastleWall* w5;
	CastleWall* w6;
	CastleTower* t1;
	CastleTower* t2;
	CastleTower* t3;
	CastleTower* t4;
	CastleTower* t5;
	CastleTower* t6;
public:
	~Castle();
	Castle();
	void draw();
};

#endif /* CASTLE_HPP_ */
