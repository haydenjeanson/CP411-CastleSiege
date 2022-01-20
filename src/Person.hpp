

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <GL/glut.h>

#include "Body.hpp"
#include "Head.hpp"

class Person: public Shape {

protected:

	Head* head;

public:
	~Person();
	Person();
	void draw();

	Body* body;
};

#endif /* PERSON_HPP_ */
