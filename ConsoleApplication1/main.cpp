#include <iostream>
#include <glut.h>
#include <vector>

#include "figura.h"

#include "HUD.h"


HUD myHUD = HUD();

point currentPointInit;
point currentPointFinal;
bool drawState = false;

colour currentColour = myHUD.getColour();


int currentFig = myHUD.getTool();



std::vector<figure *> figVec;


bool inFigure(int x, int y, figure* f)
{
	int y_aux = WSIZEY - y;
	printf("%i - %i\n", x, y);

	if (x >= f->getPointA().getPointX() &&
		x <= f->getPointB().getPointX() &&
		y_aux <= f->getPointA().getPointY() &&
		y_aux >= f->getPointB().getPointY())
	{
		printf("t");
		return true;
	}
	else
	{
		return false;
	}
}



figure * criaFigura(point a, point b, colour something, int tipo)
{
	figure * temp = new figure(a, b, something, tipo);
	figVec.push_back(temp);
	printf("Figura Criada");
	return temp;
}





void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_COLOR_LOGIC_OP);
	glLogicOp(GL_COPY);
	gluOrtho2D(0, WSIZEX, 0, WSIZEY);
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	printf("Start Render...\n");
	if (!figVec.empty())
	{
		std::vector<figure *>::iterator it = figVec.end();
		--it;
		for (std::vector<figure *>::iterator iter = figVec.begin(); iter != it; ++iter)
		{
			(*iter)->desenharFigura(false);
		}


		if (drawState)
		{
			figVec.back()->desenharFigura(true);
		}
		else
		{
			figVec.back()->desenharFigura(false);
		}
	}

	myHUD.drawHUD();
	glutSwapBuffers();
}


void rato(GLint button, GLint state, GLint x, GLint y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && inFigure(x, y, &myHUD.getBackground()))
	{

		for (auto &e : myHUD.getVectorPalette())
		{
			if (inFigure(x, y, e))
			{
				currentColour = e->getColour();
				myHUD.setColour(currentColour);
				glutPostRedisplay();
				break;
			}
		}

		for (auto &e : myHUD.getVectorTool())
		{
			if (inFigure(x, y, e))
			{
				currentFig = e->getTool();
				myHUD.setTool(currentFig);
				glutPostRedisplay();
				break;
			}
		}


	}
	else {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !inFigure(x, y, &myHUD.getBackground()))
		{
			currentPointInit.setX(x);
			currentPointInit.setY(WSIZEY - y);
			drawState = true;
			criaFigura(currentPointInit, currentPointFinal, currentColour, currentFig);

		}


		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && !inFigure(x, y, &myHUD.getBackground()))
		{
			currentPointFinal.setX(x);
			currentPointFinal.setY(WSIZEY - y);

			figVec.back()->setPointB(x, WSIZEY - y);
			drawState = false;

			glutPostRedisplay();
		}
	}
}


void moveRatoActive(GLint x, GLint y)
{
	printf("Active Movement: %d - %d\n", x, y);
	if (!figVec.empty() && drawState) {
		figVec.back()->desenharFigura(true);
		figVec.back()->setPointB(x, WSIZEY - y);
		glutPostRedisplay();
	}
}




void mykey(unsigned char key, int x, int y)
{
	switch (tolower(key))
	{
	case 'q': exit(0);
	}
}



void moveRato(int x, int y)
{
	printf("(%i,%i)\n", x, WSIZEY - y);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WSIZEX, WSIZEY);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Retro CGA Paint");
	glutDisplayFunc(display);
	glutMouseFunc(rato);
	glutMotionFunc(moveRatoActive);
	glutPassiveMotionFunc(moveRato);
	glutKeyboardFunc(mykey);
	myInit();
	glutMainLoop();
}

