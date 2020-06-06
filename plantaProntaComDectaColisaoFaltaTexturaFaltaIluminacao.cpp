#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include "textura.cpp"
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
float near = 0.1f;
float far = 20.0f;

float angulo = 0;

void desenha()
{	
	glLoadIdentity();
	float posLuz0[] = {0, 10, 0, 0};
	float luzAmb0[] = {1, 0, 0, 0};
	float luzDif0[] = {0, 1, 0, 1};
	
	float refAmb0[] = {0, 0, 0, 0};
	
	glLightfv(GL_LIGHT0, GL_POSITION, posLuz0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmb0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDif0);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, refAmb0);
		
	senoMouse = sin(xCenter*PI/180.0f);
	cosenoMouse = cos(xCenter*PI/180.0f);
	
	cout << "xEye   <- -> " << xEye << endl;
	cout << "zEye<- ->" << zEye << endl;
	
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1, 0.4, 0.7, 1.0);
	
	glLoadIdentity();	
	
	gluLookAt(xEye, yEye, zEye, senoMouse*50.0f, yCenter, -cosenoMouse*50.0f, 0, 1, 0);
	
	
	//fachada a
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-3.5, 0.4, 0);
		glTexCoord2f(1, 1);
		glVertex3f(-0.1, 0.4, 0);
		glTexCoord2f(1, 0);
		glVertex3f(-0.1, 0, 0);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	
	//fachada b
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[1]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(0.1, 0, 0);
		glTexCoord2f(0, 1);
		glVertex3f(0.1, 0.4, 0);
		glTexCoord2f(1, 1);
		glVertex3f(3.5, 0.4, 0);
		glTexCoord2f(1, 0);
		glVertex3f(3.5, 0, 0);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//fundos
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[2]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, -4);
		glTexCoord2f(0, 1);
		glVertex3f(-3.5, 0.4, -4);
		glTexCoord2f(1, 1);
		glVertex3f(3.5, 0.4, -4);
		glTexCoord2f(1, 0);
		glVertex3f(3.5, 0, -4);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//laterais
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-3.5, 0.4, 0);
		glTexCoord2f(1, 1);
		glVertex3f(-3.5, 0.4, -4);
		glTexCoord2f(1, 0);
		glVertex3f(-3.5, 0, -4);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//laterais
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(3.5, 0, 0);
		glTexCoord2f(0, 1);
		glVertex3f(3.5, 0.4, 0);
		glTexCoord2f(1, 1);
		glVertex3f(3.5, 0.4, -4);
		glTexCoord2f(1, 0);
		glVertex3f(3.5, 0, -4);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//interna verde (vide planta) a
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, -2);
		glTexCoord2f(0, 1);
		glVertex3f(-3.5, 0.4, -2);
		glTexCoord2f(1, 1);
		glVertex3f(1.9, 0.4, -2);
		glTexCoord2f(1, 0);
		glVertex3f(1.9, 0, -2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//interna verde b
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[1]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(2.1, 0, -2);
		glTexCoord2f(0, 1);
		glVertex3f(2.1, 0.4, -2);
		glTexCoord2f(1, 1);
		glVertex3f(3.5, 0.4, -2);
		glTexCoord2f(1, 0);
		glVertex3f(3.5, 0, -2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//interna azul a
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[2]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(0.5, 0, 0);
		glTexCoord2f(0, 1);
		glVertex3f(0.5, 0.4, 0);
		glTexCoord2f(1, 1);
		glVertex3f(0.5, 0.4, -0.9);
		glTexCoord2f(1, 0);
		glVertex3f(0.5, 0, -0.9);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//interna azul b
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(0.5, 0, -1.1);
		glTexCoord2f(0, 1);
		glVertex3f(0.5, 0.4, -1.1);
		glTexCoord2f(1, 1);
		glVertex3f(0.5, 0.4, -2);
		glTexCoord2f(1, 0);
		glVertex3f(0.5, 0, -2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//interna laranja a
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.5, 0, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-1.5, 0.4, 0);
		glTexCoord2f(1, 1);
		glVertex3f(-1.5, 0.4, -0.9);
		glTexCoord2f(1, 0);
		glVertex3f(-1.5, 0, -0.9);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//interna laranja b
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[1]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.5, 0, -1.1);
		glTexCoord2f(0, 1);
		glVertex3f(-1.5, 0.4, -1.1);
		glTexCoord2f(1, 1);
		glVertex3f(-1.5, 0.4, -2.9);
		glTexCoord2f(1, 0);
		glVertex3f(-1.5, 0, -2.9);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	//interna laranja c
	glColor3f(0.8, 0.3, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[2]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.5, 0, -3.1);
		glTexCoord2f(0, 1);
		glVertex3f(-1.5, 0.4, -3.1);
		glTexCoord2f(1, 1);
		glVertex3f(-1.5, 0.4, -4);
		glTexCoord2f(1, 0);
		glVertex3f(-1.5, 0, -4);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	
	
	
	//teto
	glColor3f(0.6, 0.6, 0.6);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[3]);
	glBegin(GL_QUADS);
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
	glColor3f(0.1, 0.1, 0.1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-3.5, 0, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-3.5, 0, -4);
		glTexCoord2f(1, 1);
		glVertex3f(3.5, 0, -4);
		glTexCoord2f(1, 0);
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
	
	glutSwapBuffers();	
}

void checaColisoes()
{
	if (((-3.6 <= xEye && xEye <= -3.4) && (-4 <= zEye && zEye <= 0))
	||   ((3.4 <= xEye && xEye <=  3.6) && (-4 <= zEye && zEye <= 0))
	||  ((-1.6 <= xEye && xEye <= -1.4) && ((-4<= zEye && zEye <=-3.2) || (-2.8 <= zEye && zEye <= -1.2) || (-0.8 <= zEye && zEye <=0)))
	||   ((0.4 <= xEye && xEye <= 0.6)  && ((-2<= zEye && zEye <= -1.2)|| (-0.8 <= zEye && zEye <= 0)))
	
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
		zEye -= 0.1*cosenoMouse;
		xEye += 0.1*senoMouse;		
	}
	if(tecla == 's')
	{
		zEye += 0.1*cosenoMouse;
		xEye -= 0.1*senoMouse;			
	}
	if(tecla == 'd')
	{
		xEye += 0.1*cosenoMouse;
		zEye += 0.1*senoMouse;		
	}
	if(tecla == 'a')
	{
		xEye -= 0.1*cosenoMouse;
		zEye -= 0.1*senoMouse;		
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
	glutDisplayFunc(desenha);	
	glutTimerFunc(0, timer, 0);
	
	glutKeyboardFunc(teclado);
	glutPassiveMotionFunc(posicaoMouse);
	
	glEnable(GL_DEPTH_TEST);
		
	glMatrixMode(GL_PROJECTION);
	gluPerspective(fov, 800.0f/600.f, near, far);
	glMatrixMode(GL_MODELVIEW);
	
	glGenTextures(3, texels);
	LoadBitmap("ZICA11.bmp");
	LoadBitmap("ZICA22.bmp");
	LoadBitmap("ZICA33.bmp");
	LoadBitmap("korsa2.bmp");
	
	//glEnable(GL_LIGHTING);
	
	//glEnable(GL_LIGHT0);
	
	//glShadeModel(GL_SMOOTH);
	
	glutMainLoop();	
	
	return 0;
}
