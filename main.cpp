#include <GL/freeglut.h>
#include <math.h>
#include "textura.cpp" // debian + geany
//#include "textura.h" //windows + codeblocks
#define PI 3.14159265

float xEye= 0;
float yEye =0.1;
float zEye = 4;

float xCenter = 0;
float yCenter = 0;

float senoMouse = 0;
float cosenoMouse = 1;

float fov = 45;
float near1 = 0.1;
float far1 = 20;

float angulo = 0;

void desenha()
{
	glLoadIdentity();

	senoMouse = sin(xCenter*PI/180);
	cosenoMouse = cos(xCenter*PI/180);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1, 0.4, 0.7, 1.0);

	glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		gluPerspective(fov, 800/600, near1, far1);
		gluLookAt(xEye, yEye, zEye, senoMouse*50, yCenter, -cosenoMouse*50, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    //retrato
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[1]);
	glBegin(GL_QUADS);
		glNormal3d(1, 1, 0);
		glTexCoord2f(0, 0);
		glVertex3f(0, 0.01, -2.7);
		glTexCoord2f(0, 1);
		glVertex3f(0, 0.39, -2.7);
		glTexCoord2f(1, 1);
		glVertex3f(0, 0.39, -3.3);
		glTexCoord2f(1, 0);
		glVertex3f(0, 0.01, -3.3);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//fachada a 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, -1);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, 0);
		glTexCoord2f(16, 2);
		glVertex3f(-0.1, 0.4, 0);
		glTexCoord2f(16, 0);
		glVertex3f(-0.1, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//fachada a 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 1);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, 0.0001);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, 0.0001);
		glTexCoord2f(16, 2);
		glVertex3f(-0.1, 0.4, 0.0001);
		glTexCoord2f(16, 0);
		glVertex3f(-0.1, 0, 0.0001);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//fachada b 1
	glNormal3d(0, 0, -1);
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, -1);
		glTexCoord2f(0, 0);
		glVertex3f(0.1, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(0.1, 0.4, 0);
		glTexCoord2f(16, 2);
		glVertex3f(3.5, 0.4, 0);
		glTexCoord2f(16, 0);
		glVertex3f(3.5, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//fachada b 2
	glNormal3d(0, 0, -1);
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 1);
		glTexCoord2f(0, 0);
		glVertex3f(0.1, 0, 0.0001);
		glTexCoord2f(0, 2);
		glVertex3f(0.1, 0.4, 0.0001);
		glTexCoord2f(16, 2);
		glVertex3f(3.5, 0.4, 0.0001);
		glTexCoord2f(16, 0);
		glVertex3f(3.5, 0, 0.0001);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//fundos 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, -4);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, -4);
		glTexCoord2f(32, 2);
		glVertex3f(3.5, 0.4, -4);
		glTexCoord2f(32, 0);
		glVertex3f(3.5, 0, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//fundos 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, -1);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, -4.0001);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, -4.0001);
		glTexCoord2f(32, 2);
		glVertex3f(3.5, 0.4, -4.0001);
		glTexCoord2f(32, 0);
		glVertex3f(3.5, 0, -4.0001);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais primeiros comodos a 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, 0);
		glTexCoord2f(20, 2);
		glVertex3f(-3.5, 0.4, -2);
		glTexCoord2f(20, 0);
		glVertex3f(-3.5, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais primeiros comodos a 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(-1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5001, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5001, 0.4, 0);
		glTexCoord2f(20, 2);
		glVertex3f(-3.5001, 0.4, -2);
		glTexCoord2f(20, 0);
		glVertex3f(-3.5001, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais primeiros comodos b 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(3.5001, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(3.5001, 0.4, 0);
		glTexCoord2f(20, 2);
		glVertex3f(3.5001, 0.4, -2);
		glTexCoord2f(20, 0);
		glVertex3f(3.5001, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais primeiros comodos b 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(-1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(3.5, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(3.5, 0.4, 0);
		glTexCoord2f(20, 2);
		glVertex3f(3.5, 0.4, -2);
		glTexCoord2f(20, 0);
		glVertex3f(3.5, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais fundos a 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, -2);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, -2);
		glTexCoord2f(20, 2);
		glVertex3f(-3.5, 0.4, -4);
		glTexCoord2f(20, 0);
		glVertex3f(-3.5, 0, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais fundos a 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5001, 0, -2);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5001, 0.4, -2);
		glTexCoord2f(20, 2);
		glVertex3f(-3.5001, 0.4, -4);
		glTexCoord2f(20, 0);
		glVertex3f(-3.5001, 0, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais fundos b 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(3.5, 0, -2.);
		glTexCoord2f(0, 2);
		glVertex3f(3.5, 0.4, -2);
		glTexCoord2f(20, 2);
		glVertex3f(3.5, 0.4, -4);
		glTexCoord2f(20, 0);
		glVertex3f(3.5, 0, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//laterais fundos b 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(3.5001, 0, -2.);
		glTexCoord2f(0, 2);
		glVertex3f(3.5001, 0.4, -2);
		glTexCoord2f(20, 2);
		glVertex3f(3.5001, 0.4, -4);
		glTexCoord2f(20, 0);
		glVertex3f(3.5001, 0, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo x a frente
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 1);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, -2);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, -2);
		glTexCoord2f(16, 2);
		glVertex3f(1.9, 0.4, -2);
		glTexCoord2f(16, 0);
		glVertex3f(1.9, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo x b frente
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 1);
		glTexCoord2f(0, 0);
		glVertex3f(2.1, 0, -2);
		glTexCoord2f(0, 2);
		glVertex3f(2.1, 0.4, -2);
		glTexCoord2f(4, 2);
		glVertex3f(3.5, 0.4, -2);
		glTexCoord2f(4, 0);
		glVertex3f(3.5, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo x a fundo
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, -1);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, -2.001);
		glTexCoord2f(0, 2);
		glVertex3f(-3.5, 0.4, -2.001);
		glTexCoord2f(16, 2);
		glVertex3f(1.9, 0.4, -2.001);
		glTexCoord2f(16, 0);
		glVertex3f(1.9, 0, -2.001);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo x b ffundo
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, -1);
		glTexCoord2f(0, 0);
		glVertex3f(2.1, 0, -2.001);
		glTexCoord2f(0, 2);
		glVertex3f(2.1, 0.4, -2.001);
		glTexCoord2f(4, 2);
		glVertex3f(3.5, 0.4, -2.001);
		glTexCoord2f(4, 0);
		glVertex3f(3.5, 0, -2.001);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // direita a 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(-0.5, 0.4, 0);
		glTexCoord2f(3, 2);
		glVertex3f(-0.5, 0.4, -0.9);
		glTexCoord2f(3, 0);
		glVertex3f(-0.5, 0, -0.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // x direita a 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(-1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5001, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(-0.5001, 0.4, 0);
		glTexCoord2f(3, 2);
		glVertex3f(-0.5001, 0.4, -0.9);
		glTexCoord2f(3, 0);
		glVertex3f(-0.5001, 0, -0.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // direita b 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5, 0, -1.1);
		glTexCoord2f(0, 2);
		glVertex3f(-0.5, 0.4, -1.1);
		glTexCoord2f(3, 2);
		glVertex3f(-0.5, 0.4, -2);
		glTexCoord2f(3, 0);
		glVertex3f(-0.5, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // direita b 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(-1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-0.5001, 0, -1.1);
		glTexCoord2f(0, 2);
		glVertex3f(-0.5001, 0.4, -1.1);
		glTexCoord2f(3, 2);
		glVertex3f(-0.5001, 0.4, -2);
		glTexCoord2f(3, 0);
		glVertex3f(-0.5001, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda a 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5001, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(1.5001, 0.4, 0);
		glTexCoord2f(3, 2);
		glVertex3f(1.5001, 0.4, -0.9);
		glTexCoord2f(3, 0);
		glVertex3f(1.5001, 0, -0.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda a 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(-1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5, 0, 0);
		glTexCoord2f(0, 2);
		glVertex3f(1.5, 0.4, 0);
		glTexCoord2f(3, 2);
		glVertex3f(1.5, 0.4, -0.9);
		glTexCoord2f(3, 0);
		glVertex3f(1.5, 0, -0.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda b 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5001, 0, -1.1);
		glTexCoord2f(0, 2);
		glVertex3f(1.5001, 0.4, -1.1);
		glTexCoord2f(3, 2);
		glVertex3f(1.5001, 0.4, -2);
		glTexCoord2f(3, 0);
		glVertex3f(1.5001, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda b 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(-1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5, 0, -1.1);
		glTexCoord2f(0, 2);
		glVertex3f(1.5, 0.4, -1.1);
		glTexCoord2f(3, 2);
		glVertex3f(1.5, 0.4, -2);
		glTexCoord2f(3, 0);
		glVertex3f(1.5, 0, -2);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda c 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5001, 0, -2.0001);
		glTexCoord2f(0, 2);
		glVertex3f(1.5001, 0.4, -2.0001);
		glTexCoord2f(3, 2);
		glVertex3f(1.5001, 0.4, -2.9);
		glTexCoord2f(3, 0);
		glVertex3f(1.5001, 0, -2.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda c 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5, 0, -2.0001);
		glTexCoord2f(0, 2);
		glVertex3f(1.5, 0.4, -2.0001);
		glTexCoord2f(3, 2);
		glVertex3f(1.5, 0.4, -2.9);
		glTexCoord2f(3, 0);
		glVertex3f(1.5, 0, -2.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda d 1
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5001, 0, -3.1);
		glTexCoord2f(0, 2);
		glVertex3f(1.5001, 0.4, -3.1);
		glTexCoord2f(4, 2);
		glVertex3f(1.5001, 0.4, -4);
		glTexCoord2f(4, 0);
		glVertex3f(1.5001, 0, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna eixo z // esquerda d 2
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5, 0, -3.1);
		glTexCoord2f(0, 2);
		glVertex3f(1.5, 0.4, -3.1);
		glTexCoord2f(4, 2);
		glVertex3f(1.5, 0.4, -4);
		glTexCoord2f(4, 0);
		glVertex3f(1.5, 0, -4);
	glEnd();
	glDisable(GL_TEXTURE_2D);




	//teto 1

	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, -1, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0.4, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-3.5, 0.4, -4);
		glTexCoord2f(1, 1);
		glVertex3f(3.5, 0.4, -4);
		glTexCoord2f(1, 0);
		glVertex3f(3.5, 0.4, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//teto 2

	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 1, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0.4001, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-3.5, 0.4001, -4);
		glTexCoord2f(1, 1);
		glVertex3f(3.5, 0.4001, -4);
		glTexCoord2f(1, 0);
		glVertex3f(3.5, 0.4001, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//chão
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 1, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, 0);
		glTexCoord2f(0, 10);
		glVertex3f(-3.5, 0, -4);
		glTexCoord2f(10, 10);
		glVertex3f(3.5, 0, -4);
		glTexCoord2f(10, 0);
		glVertex3f(3.5, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	
	//terreno
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
		for (GLfloat i = -4; i <= 4; i += 0.1)
		{
			glVertex3f(i, 0, 4); glVertex3f(i, 0, -4);
			glVertex3f(4, 0, i); glVertex3f(-4, 0, i);
		}		
	glEnd();

	//lâmpadas
	glPushMatrix();
        float emitB[] = {1, 1, 1, 1};
        float emit0[] = {0, 0, 0, 1};
        glMaterialfv(GL_FRONT, GL_EMISSION, emitB);
        glTranslatef(2.6, 0.35, -1.01);
        glutSolidSphere(0.02, 100, 100);
	glPopMatrix();

	glPushMatrix();
        float emitG[] = {1, 1, 1, 1};
        glMaterialfv(GL_FRONT, GL_EMISSION, emitG);
        glTranslatef(-2.6, 0.35, -1.01);
        glutSolidSphere(0.02, 100, 100);
	glPopMatrix();

	glPushMatrix();
        float emitR[] = {1, 1, 1, 1};
        glMaterialfv(GL_FRONT, GL_EMISSION, emitR);
        glTranslatef(0, 0.35, -1.01);
        glutSolidSphere(0.02, 100, 100);
        glMaterialfv(GL_FRONT, GL_EMISSION, emit0);
	glPopMatrix();
	
	
	//lanterna
    GLfloat lighpos[] = {xEye, 0.1, zEye, 1.0};
    GLfloat ligdir[] = {senoMouse*50, 0, -cosenoMouse*50};
	GLfloat lightamb4[] = {0, 0,0, 1};
	GLfloat lightdif4[] = {1., 1., 1., 1};
	GLfloat lightspec4[] = {0, 0, 0, 0};
    glLightfv(GL_LIGHT4, GL_POSITION, lighpos);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, ligdir);
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 10.0);
	glLightfv(GL_LIGHT4, GL_AMBIENT, lightamb4);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, lightdif4);
	glLightfv(GL_LIGHT4, GL_SPECULAR, lightspec4);

	glutSwapBuffers();
}

void checaColisoes()
{
	if (((-3.6 <= xEye && xEye <= -3.4) && (-4 <= zEye && zEye <= 0)) //laterais
	||   ((3.4 <= xEye && xEye <=  3.6) && (-4 <= zEye && zEye <= 0)) //laterais
	||  ((1.4 <= xEye && xEye <= 1.6) && ((-4<= zEye && zEye <=-3.2) || (-2.8 <= zEye && zEye <= -1.2) || (-0.8 <= zEye && zEye <=0)))
	||   ((-0.6 <= xEye && xEye <= -0.4)  && ((-2<= zEye && zEye <= -1.2)|| (-0.8 <= zEye && zEye <= 0)))

	||  ((-0.1 <= zEye && zEye <= 0.1)  &&((-3.5<=xEye && xEye <= -0.2)|| (0.2 <=  xEye && xEye <= 3.5)))
	||  ((-2.1 <= zEye && zEye <= -1.9) &&((-3.5<=xEye && xEye <= 1.8) || (2.2 <=  xEye && xEye <= 3.5)))
	||  ((-4.1 <= zEye && zEye <= -3.9) && (-3.5<=xEye && xEye <= 3.5)))


	{
		xEye= 0;
		zEye = 4;
	}
}


void timer(int t)
{
	checaColisoes();
	angulo++;
	glutPostRedisplay();
	glutTimerFunc(60, timer, 0);
}

void posicaoMouse(int x, int y)
{
	xCenter = (x - 400);
	yCenter = (300 - y)/2;
}

void teclado (unsigned char tecla, int x, int y)
{
	if((tecla == 'w')|| (tecla == 'W'))
	{
		zEye -= 0.08*cosenoMouse;
		xEye += 0.08*senoMouse;
	}
	
	if((tecla == 's')|| (tecla == 'S'))
	{
		zEye += 0.08*cosenoMouse;
		xEye -= 0.08*senoMouse;
	}
	
	if((tecla == 'd')|| (tecla == 'D'))
	{
		xEye += 0.08*cosenoMouse;
		zEye += 0.08*senoMouse;
	}
	
	if((tecla == 'a')|| (tecla == 'A'))
	{
		xEye -= 0.08*cosenoMouse;
		zEye -= 0.08*senoMouse;
	}	
	
	if((tecla == 'i')|| (tecla == 'I'))
	{
		glDisable(GL_LIGHT0);
	}

	if((tecla == 'o')|| (tecla == 'O'))
	{
		glDisable(GL_LIGHT1);
	}

	if((tecla == 'p')|| (tecla == 'P'))
	{
		glDisable(GL_LIGHT2);
	}

	if((tecla == 'j')|| (tecla == 'J'))
	{
		glEnable(GL_LIGHT0);
	}

	if((tecla == 'k')|| (tecla == 'K'))
	{
		glEnable(GL_LIGHT1);
	}

	if((tecla == 'l')|| (tecla == 'L'))
	{
		glEnable(GL_LIGHT2);
	}

	if((tecla == 'f')|| (tecla == 'F'))
	{
		glEnable(GL_LIGHT4);
	}

	if((tecla == 'g')|| (tecla == 'G'))
	{
		glDisable(GL_LIGHT4);
	}
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutCreateWindow("MANSÃO SINISTRA");
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat lightamb[] = {0, 0,0, 0};
	GLfloat lightdif[] = {0, 0., 1, 1};
	GLfloat lightspec[] = {0, 0, 0, 0};
	GLfloat lightpos[] = {0, 0.35, -1.01, 1};
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightamb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightspec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	glEnable(GL_LIGHT1);
	GLfloat lightamb1[] = {0, 0,0, 0};
	GLfloat lightdif1[] = {0, 1, 0, 1};
	GLfloat lightspec1[] = {0, 0, 0, 0};
	GLfloat lightpos1[] = {-2.6, 0.35, -1.01, 1};
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightamb1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightdif1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightspec1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightpos1);

	glEnable(GL_LIGHT2);
	GLfloat lightamb2[] = {0, 0,0, 0};
	GLfloat lightdif2[] = {1, 0, 0, 1};
	GLfloat lightspec2[] = {0, 0, 0, 0};
	GLfloat lightpos2[] = {2.6, 0.35, -1.01, 1};
	glLightfv(GL_LIGHT2, GL_AMBIENT, lightamb2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightdif2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lightspec2);
	glLightfv(GL_LIGHT2, GL_POSITION, lightpos2);

	glEnable(GL_LIGHT3);
	GLfloat lightamb3[] = {0.25, 0.25,0.25, 1};
	GLfloat lightdif3[] = {0., 0., 0., 1};
	GLfloat lightspec3[] = {0, 0, 0, 0};
	GLfloat lightpos3[] = {0, 10, 0, 1};
	glLightfv(GL_LIGHT3, GL_AMBIENT, lightamb3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, lightdif3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, lightspec3);
	glLightfv(GL_LIGHT3, GL_POSITION, lightpos3);

	glutDisplayFunc(desenha);
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(teclado);
	glutPassiveMotionFunc(posicaoMouse);
	glEnable(GL_DEPTH_TEST);

	glGenTextures(3, texels);
	LoadBitmap("assets/parede.bmp");
	LoadBitmap("assets/retrato.bmp");

	glutMainLoop();

	return 0;
}
