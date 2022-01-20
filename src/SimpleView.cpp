/*
 *  SimpleView3 : reference design
 *  Author: HBF
 *  Version: 2021-11-01
 */



#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "pixmap/RGBpixmap.h"
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "time.h"
#include <windows.h>  // for playing sound
#include <mmsystem.h>



GLint winWidth = 1280, winHeight = 720;
GLint isInMove = 0,
	  xbegin = 0,
	  csType = 1,    /* coordinate system type: 1 for MCS, 2 for WCS, 3 for VCS */
	  transType = 4;  /* depends on csType  */

CullMode cullMode = GLCULLDEPTHBUFFER;      /* culling option */
RenderMode renderMode = TEXTURE; //  WIRE;  /* shade option  */

World myWorld;
Camera myCamera;
Shape *selectObj = NULL;  // pointer to select object
GLint displayOption = 0;   /* 0: world, 1: solar system, 2: control points, 3: curve, 4: rotation surface.  */

RGBpixmap pix[6];      /* pixmaps for 6 textures */

const GLint NUM_MOVING_PEOPLE = 3;
GLint direction[NUM_MOVING_PEOPLE];   /* direction of people movement */
GLint animationCounter[NUM_MOVING_PEOPLE];
GLint randDistance[NUM_MOVING_PEOPLE];


void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	selectObj = myWorld.searchById(3);

	/* load six texture bitmap */
	pix[0].readBMPFile("grass.bmp");
	pix[0].setTexture(0);

	pix[1].readBMPFile("posy.bmp");
	pix[1].setTexture(1);

	pix[2].readBMPFile("mountainsky.bmp");
	pix[2].setTexture(2);

	pix[3].readBMPFile("mountainsky.bmp");
	pix[3].setTexture(3);

	pix[4].readBMPFile("mountainsky.bmp");
	pix[4].setTexture(4);

	pix[5].readBMPFile("mountainsky.bmp");
	pix[5].setTexture(5);

	pix[6].readBMPFile("cementD.bmp");
	pix[6].setTexture(6);

	pix[7].readBMPFile("cementB.bmp");
	pix[7].setTexture(7);

    pix[8].readBMPFile("stonekeep.bmp");
    pix[8].setTexture(8);

	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	srand(time(NULL));

	for (int i = 0; i < NUM_MOVING_PEOPLE; i++) {
		animationCounter[i] = 0;
		direction[i] = 1;
		randDistance[i] = rand() % 50 + 10;
	}

	PlaySound((LPCSTR) "castle_background.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myCamera.setProjectionMatrix();
	myWorld.draw();

	glFlush();
	glutSwapBuffers();
}


void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void mouseActionFcn(int button, int state, int xMouse, int yMouse) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		isInMove = 1;
		xbegin = xMouse;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		isInMove = 0;
	}
}

void mouseMotionFcn(GLint xMouse, GLint yMouse) {
	if (isInMove) {
		if(csType == 3){
			VCSTransform(xMouse);
		}
		glutPostRedisplay();
	}
}


int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Storm the Castle! (Hussain Phalasiya, Hayden Jeanson, Jordan Den Hoed) ");

	glewInit(); // this is for GSLS

	menu();
	init();


	glutDisplayFunc(display);
	glutMotionFunc(mouseMotionFcn);
	glutMouseFunc(mouseActionFcn);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
