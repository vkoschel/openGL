#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include "textura.cpp" // debian + geany
//#include "textura.h" //ruindows + cockblock
#define PI 3.14159265

using namespace std;

float xEye= 0;
float yEye =0.1;
float zEye = 4;

float xCenter = 0;
float yCenter = 0;

float senoMouse = 0;
float cosenoMouse = 1;

float fov = 45.0f;
float near1 = 0.1f;
float far1 = 20.0f;

float angulo = 0;

void desenha()
{
	glLoadIdentity();

	senoMouse = sin(xCenter*PI/180.0f);
	cosenoMouse = cos(xCenter*PI/180.0f);

	cout << "xEye   <- -> " << xEye << endl;
	cout << "zEye<- ->" << zEye << endl;



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1, 0.4, 0.7, 1.0);

	
	glMatrixMode(GL_PROJECTION);
	
		glLoadIdentity();	
		gluPerspective(fov, 800.0f/600.f, near1, far1);
		gluLookAt(xEye, yEye, zEye, senoMouse*50.0f, yCenter, -cosenoMouse*50.0f, 0, 1, 0);
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();


	//fachada a
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


	//fachada b
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

	//fundos
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(0, 0, -1);
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

	//laterais primeiros comodos
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

	//laterais primeiros comodos
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
	
	//laterais fundos
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
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

	//laterais fundos
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(-1, 0, 0);
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

	//interna verde (vide planta) a frente
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

	//interna verde b frente
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
	
	//interna verde (vide planta) a fundo
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

	//interna verde b ffundo
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

	//interna azul a
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

	//interna azul b
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

	//interna laranja a
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
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

	//interna laranja b
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
		glTexCoord2f(0, 0);
		glVertex3f(1.5, 0, -1.1);
		glTexCoord2f(0, 2);
		glVertex3f(1.5, 0.4, -1.1);
		glTexCoord2f(3, 2);
		glVertex3f(1.5, 0.4, -2.9);
		glTexCoord2f(3, 0);
		glVertex3f(1.5, 0, -2.9);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//interna laranja c
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glNormal3d(1, 0, 0);
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




	//teto
	
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


	glColor3f(0, 0, 0);

	glBegin(GL_LINES);
		for (GLfloat i = -4; i <= 4; i += 0.1)
		{
			glVertex3f(i, 0, 4); glVertex3f(i, 0, -4);
			glVertex3f(4, 0, i); glVertex3f(-4, 0, i);
		}
	glEnd();
	
	glPushMatrix();
	
	float emit[] = {1, 1, 1, 1};
	float emit0[] = {0.1, 0.1, 0.1, 1};
	glMaterialfv(GL_FRONT, GL_EMISSION, emit);
	glTranslatef(-2.6, 0.35, -1.01);
	glutSolidSphere(0.02, 100, 100);
	//glMaterialfv(GL_FRONT, GL_EMISSION, emit0);
	
	
	glPopMatrix();
	
	glPushMatrix();
	
	
	glMaterialfv(GL_FRONT, GL_EMISSION, emit);
	glTranslatef(2.6, 0.35, -1.01);
	glutSolidSphere(0.02, 100, 100);
	//glMaterialfv(GL_FRONT, GL_EMISSION, emit0);
	
	
	glPopMatrix();
	
	glPushMatrix();
	
	
	glMaterialfv(GL_FRONT, GL_EMISSION, emit);
	glTranslatef(0, 0.35, -1.01);
	glutSolidSphere(0.02, 100, 100);
	glMaterialfv(GL_FRONT, GL_EMISSION, emit0);
	
	
	glPopMatrix();

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
	if(tecla == 'w')
	{
		zEye -= 0.08*cosenoMouse;
		xEye += 0.08*senoMouse;
	}
	if(tecla == 's')
	{
		zEye += 0.08*cosenoMouse;
		xEye -= 0.08*senoMouse;
	}
	if(tecla == 'd')
	{
		xEye += 0.08*cosenoMouse;
		zEye += 0.08*senoMouse;
	}
	if(tecla == 'a')
	{
		xEye -= 0.08*cosenoMouse;
		zEye -= 0.08*senoMouse;
	}
	if(tecla == 'y')
	{
		yEye ++;

	}
	if(tecla == 'h')
	{
		yEye --;

	}
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutCreateWindow("dale");
	
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	
	GLfloat lightamb[] = {0, 0,0, 0};
	GLfloat lightdif[] = {1, 1, 1, 1};
	GLfloat lightspec[] = {0, 0, 0, 1};
	GLfloat lightpos[] = {0, 0.1, -0.5, 1};
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightamb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightdif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightspec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	
	
	glEnable(GL_LIGHT1);
	
	GLfloat lightamb1[] = {0, 0,0, 0};
	GLfloat lightdif1[] = {1, 1, 1, 1};
	GLfloat lightspec1[] = {0, 0, 0, 1};
	GLfloat lightpos1[] = {-2.6, 0.1, -0.5, 1};
	
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightamb1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightdif1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightspec1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightpos1);
	
	
	glEnable(GL_LIGHT2);
	
	GLfloat lightamb2[] = {0, 0,0, 0};
	GLfloat lightdif2[] = {1, 1, 1, 1};
	GLfloat lightspec2[] = {0, 0, 0, 1};
	GLfloat lightpos2[] = {2.6, 0.1, -0.5, 1};
	
	glLightfv(GL_LIGHT2, GL_AMBIENT, lightamb2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightdif2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lightspec2);
	glLightfv(GL_LIGHT2, GL_POSITION, lightpos2);
	
	glutDisplayFunc(desenha);
	glutTimerFunc(0, timer, 0);

	glutKeyboardFunc(teclado);
	glutPassiveMotionFunc(posicaoMouse);

	glEnable(GL_DEPTH_TEST);

	glGenTextures(1, texels);
	LoadBitmap("assets/parede.bmp");	



	glutMainLoop();

	return 0;
}
