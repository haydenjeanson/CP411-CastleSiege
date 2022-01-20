/*
 * guard.hpp
 *
 *  Created on: Dec 7, 2021
 *      Author: hayde
 */

#ifndef SRC_GUARD_HPP_
#define SRC_GUARD_HPP_

#include <GL/glut.h>

#include "Person.hpp"

class Guard: public Shape {

protected:
	Person* person;

public:
	~Guard();
	Guard();
	void draw();
};


#endif /* SRC_GUARD_HPP_ */
