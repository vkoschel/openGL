#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include "textura.cpp"
#define PI 3.14159265

using namespace std;

float xEye= 0;
float zEye = 3;

float xCenter = 0;
float yCenter = 0;

float senoMouse = 0;
float cosenoMouse = 1;

float fov = 45.0f;
float near = 0.1f;
float far = 20.0f;

void desenha()
{		
	senoMouse = sin(xCenter*PI/180.0f);
	cosenoMouse = cos(xCenter*PI/180.0f);
	
	//cout << "sin mouse <- -> " << senoMouse << endl;
	//cout << "cos mouse <- ->" << cosenoMouse << endl;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1, 0.4, 0.7, 1.0);
	
	glLoadIdentity();	
	
	gluLookAt(xEye, 0, zEye, senoMouse*50.0f, yCenter, -cosenoMouse*50.0f, 0, 1, 0);	
	
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex2f(-0.2, -0.2);
		glTexCoord2f(0, 1);
		glVertex2f(-0.2, 0.2);
		glTexCoord2f(1, 1);
		glVertex2f(0.2, 0.2);
		glTexCoord2f(1, 0);
		glVertex2f(0.2, -0.2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[1]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-0.2, -0.2, -2);
		glTexCoord2f(0, 1);
		glVertex3f(-0.2, 0.2, -2);
		glTexCoord2f(1, 1);
		glVertex3f(0.2, 0.2, -2);
		glTexCoord2f(1, 0);
		glVertex3f(0.2, -0.2, -2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[2]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-0.2, -0.2, 2);
		glTexCoord2f(0, 1);
		glVertex3f(-0.2, 0.2, 2);
		glTexCoord2f(1, 1);
		glVertex3f(0.2, 0.2, 2);
		glTexCoord2f(1, 0);
		glVertex3f(0.2, -0.2, 2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(2, -0.2, -0.2);
		glTexCoord2f(0, 1);
		glVertex3f(2, -0.2, 0.2);
		glTexCoord2f(1, 1);
		glVertex3f(2, 0.2, 0.2);
		glTexCoord2f(1, 0);
		glVertex3f(2, 0.2, -0.2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texels[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-2, -0.2, -0.2);
		glTexCoord2f(0, 1);
		glVertex3f(-2, -0.2, 0.2);
		glTexCoord2f(1, 1);
		glVertex3f(-2, 0.2, 0.2);
		glTexCoord2f(1, 0);
		glVertex3f(-2, 0.2, -0.2);	
	glEnd();	
	glDisable(GL_TEXTURE_2D);
	
	glutWireCube(0.8);	
	
	glColor3f(0.1, 1.0, 0.1);
	glTranslatef(0, -0.4 ,0);
	glBegin(GL_LINES);
		for (GLfloat i = -2.5; i <= 2.5; i += 0.1)
		{
			glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
			glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
		}
	glEnd();
	
	glutSwapBuffers();	
}

void timer(int t)
{		
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
	
	glutMainLoop();	
	
	return 0;
}
