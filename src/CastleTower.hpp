

#ifndef CASTLETOWER_HPP_
#define CASTLETOWER_HPP_

#include <GL/glut.h>

#include "Tower.hpp"
#include "Roof.hpp"

class CastleTower: public Shape {
protected:
	Tower* tower;
	Roof* roof;

public:
	~CastleTower();
	CastleTower();
	void draw();
};

#endif /* CASTLETOWER_HPP_ */
