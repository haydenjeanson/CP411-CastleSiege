#include "World.hpp"
#include "Cube.hpp"
#include "Castle.hpp"
#include "Guard.hpp"
using namespace std;

const GLint CUBE_SIZE = 15;

World::World() {
	Shape *obj = NULL;

    /* add Cube into the world object list */
	// This cube is the CUBEMAP, used to design the skybox
	obj = new Cube();
	obj->setId(999);
	obj->scaleChange(CUBE_SIZE);
	objlist.push_back(obj);

	/* add Castle into the world object list */
	obj = new Castle();
	obj->setId(1);
	obj->scaleChange(-0.2);
	obj->rotate(0, 0, 1, 90);
	obj->translate(9, 0, -CUBE_SIZE-1);
	objlist.push_back(obj);

	/* add moving people into the world object list */
	obj = new Person();
	obj->setId(2);
	obj->scaleChange(-0.2);
	obj->translate(0, 0.7, -CUBE_SIZE-1);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(3);
	obj->scaleChange(-0.2);
	obj->translate(0, 0.3, -CUBE_SIZE-1);
	objlist.push_back(obj);

	/* add patrol guard into the world object list */
	obj = new Guard();
	obj->setId(4);
	obj->scaleChange(-0.2);
	obj->translate(9, 7, -CUBE_SIZE-1);
	objlist.push_back(obj);

	/* add stationary guards into the world object list */
	obj = new Guard();
	obj->setId(5);
	obj->scaleChange(-0.2);
	obj->translate(2.4, -0.9, -CUBE_SIZE-1);
	objlist.push_back(obj);

	obj = new Guard();
	obj->setId(6);
	obj->scaleChange(-0.2);
	obj->translate(2.4, 0.9, -CUBE_SIZE-1);
	objlist.push_back(obj);

	/* add stationary people into the world object list */
	obj = new Person();
	obj->setId(7);
	obj->scaleChange(-0.2);
	obj->translate(0, 4, -CUBE_SIZE-1);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(8);
	obj->scaleChange(-0.2);
	obj->translate(0.3, 4.4, -CUBE_SIZE-1);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(9);
	obj->scaleChange(-0.2);
	obj->translate(0.7, 4.6, -CUBE_SIZE-1);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(10);
	obj->scaleChange(-0.2);
	obj->translate(0.7, -6.6, -CUBE_SIZE-1);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(11);
	obj->scaleChange(-0.2);
	obj->translate(0.3, -6.2, -CUBE_SIZE-1);
	objlist.push_back(obj);

	obj = new Person();
	obj->setId(12);
	obj->scaleChange(-0.2);
	obj->translate(0.1, -5.9, -CUBE_SIZE-1);
	objlist.push_back(obj);
}

World::~World(){
	Shape *obj;
	while (!objlist.empty()) {
		obj = objlist.front();
		objlist.pop_front();
		free(obj);
	}
}

void lineSegment(float x1, float y1, float z1, float x2, float y2, float z2) {
	glBegin(GL_LINES);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glEnd();
}

void World::draw() {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  (*it)->draw();
    }
}

void World::reset(){
	Shape *obj = NULL;

	obj = this->searchById(1);
	obj->reset();
	obj->setScale(0.5);
	obj->translate(2.5, 0, 0);

	obj = this->searchById(2);
	obj->reset();
	obj->setScale(0.5);
	obj->translate(4, 0, 0);

	obj = this->searchById(3);
	obj->reset();
	obj->setScale(0.5);
}

Shape* World::searchById(GLint i) {
	std::list<Shape*>::iterator it;
	for (it = objlist.begin(); it !=  objlist.end(); ++it) {
	  if ((*it)->getId() == i) return *it;
    }
	return NULL;
}

