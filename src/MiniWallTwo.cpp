#include "MiniWallTwo.hpp"
#include "Camera.hpp"
#include <stdio.h>

extern Camera myCamera;
extern CullMode cullMode;

MiniWallTwo::MiniWallTwo() {
	vertex[0][0] = -5; vertex[0][1] = -0.5; vertex[0][2] = 2;
	vertex[1][0] = -5; vertex[1][1] = 0.5;  vertex[1][2] = 2;
	vertex[2][0] = 5;  vertex[2][1] = 0.5;  vertex[2][2] = 2;
	vertex[3][0] = 5;  vertex[3][1] = -0.5; vertex[3][2] = 2;
	vertex[4][0] = -5; vertex[4][1] = -0.5; vertex[4][2] = 3;
	vertex[5][0] = -5; vertex[5][1] = 0.5;  vertex[5][2] = 3;
	vertex[6][0] = 5;  vertex[6][1] = 0.5;  vertex[6][2] = 3;
	vertex[7][0] = 5;  vertex[7][1] = -0.5; vertex[7][2] = 3;

	face[0][0] = 0; face[0][1] = 1; face[0][2] = 2; face[0][3] = 3;
	face[1][0] = 7; face[1][1] = 6; face[1][2] = 5; face[1][3] = 4;
	face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1;
	face[3][0] = 2; face[3][1] = 1; face[3][2] = 5; face[3][3] = 6;
	face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7;
	face[5][0] = 0; face[5][1] = 3; face[5][2] = 7; face[5][3] = 4;

	faceColor[0][0] = 1.0; faceColor[0][1] = 0.0; faceColor[0][2] = 0.0;
	faceColor[1][0] = 0.0; faceColor[1][1] = 1.0; faceColor[1][2] = 0.0;
	faceColor[2][0] = 0.0; faceColor[2][1] = 0.0; faceColor[2][2] = 1.0;
	faceColor[3][0] = 1.0; faceColor[3][1] = 1.0; faceColor[3][2] = 0.0;
	faceColor[4][0] = 0.0; faceColor[4][1] = 1.0; faceColor[4][2] = 1.0;
	faceColor[5][0] = 1.0; faceColor[5][1] = 0.0; faceColor[5][2] = 1.0;

	for (int i = 0 ; i<6; i++) {
		Vector V1 = Vector(vertex[face[i][1]][0]-vertex[face[i][0]][0], vertex[face[i][1]][1]-vertex[face[i][0]][1], vertex[face[i][1]][2]-vertex[face[i][0]][2]);
		Vector V2 = Vector(vertex[face[i][2]][0]-vertex[face[i][1]][0], vertex[face[i][2]][1]-vertex[face[i][1]][1], vertex[face[i][2]][2]-vertex[face[i][1]][2]);
		Vector V3 =  V1.cross(V2);
		V3.normalize();
		faceNormal[i][0] = V3.x;
		faceNormal[i][1] = V3.y;
		faceNormal[i][2] = V3.z;
	}

	r = 0.5;
	g = 0.6;
	b = 0.7;
}

void MiniWallTwo::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);

	for (int i = 0; i < 6; i++) {
		if (cullMode == BACKFACE) {
			if (isFrontface(i, myCamera)) {
				drawFace(i);
			}
		}
		else {
			drawFace(i);
		}
	}

	glPopMatrix();
}

void MiniWallTwo::drawFace(int i) {
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3fv(&vertex[face[i][0]][0]);
	glTexCoord2f(1.0, 0.0); glVertex3fv(&vertex[face[i][1]][0]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(&vertex[face[i][2]][0]);
	glTexCoord2f(0.0, 1.0); glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

bool MiniWallTwo::isFrontface(int faceindex, Camera camera) {
	GLfloat v[4];
	v[0] = faceNormal[faceindex][0];  // get faceNormal in MCS
	v[1] = faceNormal[faceindex][1];
	v[2] = faceNormal[faceindex][2];
	v[3] = 0.0;
	mc.multiplyVector(v);   // compute faceNormal in WCS

	if (pmc != NULL) {  // if parent MCS exists, use the parent's origin as reference point.
		pmc->multiplyVector(v);
		return (pmc->mat[0][3] - camera.eye.x) * v[0] + (pmc->mat[1][3] - camera.eye.y) * v[1] + (pmc->mat[2][3] - camera.eye.z) * v[2] < 0;
	} else {
		return (mc.mat[0][3] - camera.eye.x) * v[0] + (mc.mat[1][3] - camera.eye.y) * v[1] + (mc.mat[2][3] - camera.eye.z) * v[2] < 0;
	}
}
