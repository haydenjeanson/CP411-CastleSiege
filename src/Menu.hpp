/*
 *  SimpleView : reference design
 *  Author: HBF
 *  Version: 2021-10-15
 */
#ifndef MENU_HPP_
#define MENU_HPP_

#include <GL/glut.h>

void menu();
void mainMenu(GLint option);
void VCSTransMenu(GLint transOption);
void VCSTransform(GLint);

void speedMenu(GLint speed);
void animateMenu(GLint option);

#endif
