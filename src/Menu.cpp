/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2021-10-15
 */
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"

extern GLint csType;
extern GLint transType, xbegin;
extern World myWorld;
extern Camera myCamera;

extern GLint direction[]; /* Direction of people movement */
extern GLint animationCounter[];
extern GLint randDistance[];
GLint pathPhase = 0;
GLint speedInverse = 8;

void menu() {
	GLint VCTrans_Menu = glutCreateMenu(VCSTransMenu);
	glutAddMenuEntry("Rotate x", 1);
	glutAddMenuEntry("Rotate y", 2);
	glutAddMenuEntry("Rotate z", 3);
	glutAddMenuEntry("Translate x", 4);
	glutAddMenuEntry("Translate y", 5);
	glutAddMenuEntry("Translate z", 6);

	GLint Speed_Menu = glutCreateMenu(speedMenu);
	glutAddMenuEntry("1", 1);
	glutAddMenuEntry("2", 5);
	glutAddMenuEntry("3", 7);
	glutAddMenuEntry("4", 8);
	glutAddMenuEntry("5", 9);
	glutAddMenuEntry("6", 10);

	glutCreateMenu(mainMenu);
	glutAddSubMenu("Camera Controls", VCTrans_Menu);
	glutAddSubMenu("Animation Speed", Speed_Menu);
	glutAddMenuEntry("Animate People", 1);
	glutAddMenuEntry("Stop Animation", 2);
	glutAddMenuEntry("Quit", 3);
}

void mainMenu(GLint option) {
	switch (option){
		case 1:
		case 2:
			animateMenu(option);
			break;
		case 3:
			exit(0);
			break;
	}
	glutPostRedisplay();
}

void VCSTransMenu(GLint transOption) {
	csType = 3;
	transType = transOption;
	glutPostRedisplay();
}

void VCSTransform(GLint x){
	GLfloat theta = (xbegin - x > 0) ? 1 : -1;
	if (transType == 1) {  //eye rotate x
		myCamera.rotate(1.0, 0.0, 0.0, theta*0.5);
	}
	else if (transType == 2) { // eye rotate y
		myCamera.rotate(0.0, 1.0, 0.0, theta*0.5);
	}
	else if(transType == 3){ //eye rotate z
		myCamera.rotate(0.0, 0.0, 1.0, theta*0.5);
	}
	else if (transType == 4) { //eye translate x
		myCamera.translate(theta* 0.02, 0.0, 0.0);
	}
	else if(transType == 5){   // eye translate y
		myCamera.translate(0.0, theta* 0.02, 0.0);
	}
	else if(transType == 6){ // eye translate z
		myCamera.translate(0.0, 0.0, theta* 0.02);
	}
	else if(transType == 7){  // change dnear
		myCamera.dnear += theta * .1;
	}
	else if(transType == 8){  // change dfar
		myCamera.dfar += theta *.1;
	}
}

void speedMenu(GLint speed) {
	// 1, 3, 5, 7,8,8,10
	speedInverse = 11-speed;
}

void animateEntrancePeople(void) {
	for (int i = 0; i < 2; i++) {

		animationCounter[i] += 1;
		if (myWorld.searchById(i+2)->getMC().mat[0][3] <= -7 && direction[i] == -1) {
			direction[i] *= -1;

		} else if (myWorld.searchById(i+2)->getMC().mat[0][3] >= 11 && direction[i] == 1) {
			direction[i] *= -1;
		}

		myWorld.searchById(i+2)->translate(0.1 * direction[i] / speedInverse, -0.01 * direction[i] / speedInverse, 0);
		glutPostRedisplay();

		if (animationCounter[i] >= randDistance[i] * speedInverse) {
			randDistance[i] = rand() % 50 + 10;
			animationCounter[i] = 0;
			direction[i] *= -1;
		}
	}
}

void animatePatrol(void) {
	GLint patrolId = 4;

	if (pathPhase == 0) {
		myWorld.searchById(patrolId)->translate(-0.1 * direction[2] / speedInverse / 2, -0.1 * direction[2] / speedInverse / 2 , 0);

		if (myWorld.searchById(patrolId)->getMC().mat[0][3] <= 5.5) {
			pathPhase++;
		}
	} else if (pathPhase == 1) {
		myWorld.searchById(patrolId)->translate(0, -0.1 * direction[2] / speedInverse / 2 , 0);

		if (myWorld.searchById(patrolId)->getMC().mat[1][3] <= -2.5) {
			pathPhase++;
		}
	} else if (pathPhase == 2) {
		myWorld.searchById(patrolId)->translate(0.1 * direction[2] / speedInverse / 2, -0.1 * direction[2] / speedInverse / 2 , 0);

		if (myWorld.searchById(patrolId)->getMC().mat[1][3] <= -6.4) {
			pathPhase++;
		}
	} else if (pathPhase == 3) {
		myWorld.searchById(patrolId)->translate(0.1 * direction[2] / speedInverse / 2, 0.1 * direction[2] / speedInverse / 2 , 0);

		if (myWorld.searchById(patrolId)->getMC().mat[0][3] >= 12.5) {
			pathPhase++;
		}
	} else if (pathPhase == 4) {

		myWorld.searchById(patrolId)->translate(0, 0.1 * direction[2] / speedInverse / 2 , 0);
		if (myWorld.searchById(patrolId)->getMC().mat[1][3] >= 3.5) {
			pathPhase++;
		}
	} else if (pathPhase == 5) {
		myWorld.searchById(patrolId)->translate(-0.1 * direction[2] / speedInverse / 2, 0.1 * direction[2] / speedInverse / 2 , 0);
		if (myWorld.searchById(patrolId)->getMC().mat[1][3] >= 7) {

			GLfloat xDiff = myWorld.searchById(patrolId)->getMC().mat[0][3] - 9;
			GLfloat yDiff = myWorld.searchById(patrolId)->getMC().mat[1][3] - 7;

			myWorld.searchById(patrolId)->translate(-xDiff, 0, 0);
			myWorld.searchById(patrolId)->translate(-yDiff, 0, 0);
			if (myWorld.searchById(patrolId)->getMC().mat[0][3] <= 9) {
				pathPhase = 0;
			}
		}
	}
}

void animate(void) {
	animateEntrancePeople();
	animatePatrol();
}

void animateMenu(GLint option ) {
	switch (option){
		case 1:
			glutIdleFunc(animate);
			break;
		case 2:
			glutIdleFunc(NULL);
			break;
	}
	glutPostRedisplay();
}
