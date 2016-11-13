#include "figura.h"
#include <glut.h>


figure::figure()
{
}

figure::figure(point _a, point _b, colour _cor, int _type)
{
	a = _a;
	b = _b;
	type = _type;
	cor = _cor;
}

figure::figure(point _a, point _b, colour _cor, int _type, int _toolType)
{
	a = _a;
	b = _b;
	type = _type;
	cor = _cor;
	toolType = _toolType;
}


void figure::setTipo(int tipo)
{
	type = tipo;
}

int figure::getTipo()
{
	return type;
}

point figure::getPointA()
{
	return a;
}

point figure::getPointB()
{
	return b;
}

colour figure::getColour()
{
	return cor;
}

int figure::getTool()
{
	return toolType;
}

void figure::setColour(colour _cor)
{
	cor = _cor;
}

void figure::setPointA(int, int)
{
}

void figure::setPointB(int x, int y)
{
	b.setX(x);
	b.setY(y);
}

void figure::desenharFigura(bool xor)
{
	switch (this->getTipo())
	{
	case 1:

		if (xor == true)
		{
			glLogicOp(GL_XOR);
			glLineStipple(3, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1);
		}
		if (xor == false)
		{
			glBegin(GL_POLYGON);
			glColor3f(this->getColour().getRed(), this->getColour().getGreen(), this->getColour().getBlue());
		}

		glVertex2i(this->getPointA().getPointX(), this->getPointA().getPointY());
		glVertex2i(this->getPointB().getPointX(), this->getPointA().getPointY());
		glVertex2i(this->getPointB().getPointX(), this->getPointB().getPointY());
		glVertex2i(this->getPointA().getPointX(), this->getPointB().getPointY());
		glEnd();
		glFlush();
		if (xor) { glLogicOp(GL_COPY); glDisable(GL_LINE_STIPPLE); }

		break;

	case 2:
		if (xor == true)
		{
			glLogicOp(GL_XOR);
			glLineStipple(3, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINES);
			glColor3f(1, 1, 1);
		}
		else {
			glBegin(GL_LINES);
			glColor3f(this->getColour().getRed(), this->getColour().getGreen(), this->getColour().getBlue());
			glLineWidth(2.5);
		}

		glVertex2i(this->getPointA().getPointX(), this->getPointA().getPointY());
		glVertex2i(this->getPointB().getPointX(), this->getPointB().getPointY());
		glEnd();
		glFlush();
		if (xor) { glLogicOp(GL_COPY); glDisable(GL_LINE_STIPPLE); }

		break;

	case 3:
		if (xor == true)
		{
			glLogicOp(GL_XOR);
			glLineStipple(3, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1);
		}
		else {
			glBegin(GL_TRIANGLES);
			glColor3f(this->getColour().getRed(), this->getColour().getGreen(), this->getColour().getBlue());
		}
		glVertex2i(this->getPointA().getPointX(), this->getPointA().getPointY());
		glVertex2i(this->getPointA().getPointX() - ((this->getPointB().getPointX()) - (this->getPointA().getPointX())), this->getPointB().getPointY());
		glVertex2i(this->getPointB().getPointX(), this->getPointB().getPointY());
		glEnd();

		if (xor) { glLogicOp(GL_COPY); glDisable(GL_LINE_STIPPLE); }
		break;


	case 4:


		if (xor == true)
		{
			glLogicOp(GL_XOR);
			glLineStipple(3, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1);
		}
		else {
			glBegin(GL_LINE_LOOP);
			glColor3f(this->getColour().getRed(), this->getColour().getGreen(), this->getColour().getBlue());
		}

		glVertex2i(this->getPointA().getPointX(), this->getPointA().getPointY());
		glVertex2i(this->getPointB().getPointX(), this->getPointA().getPointY());
		glVertex2i(this->getPointB().getPointX(), this->getPointB().getPointY());
		glVertex2i(this->getPointA().getPointX(), this->getPointB().getPointY());
		glEnd();
		if (xor) { glLogicOp(GL_COPY); glDisable(GL_LINE_STIPPLE); }

		break;

	case 5:
	{

		int x1 = this->a.getPointX();
		int x2 = this->b.getPointX();
		int y1 = this->a.getPointY();
		int y2 = this->b.getPointY();

		float r = sqrt((((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2))));

		if (xor == true)
		{
			glLogicOp(GL_XOR);
			glLineStipple(3, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1);
		}
		if (xor == false)
		{
			glBegin(GL_POLYGON);
			glColor3f(this->getColour().getRed(), this->getColour().getGreen(), this->getColour().getBlue());
		}

		for (int i = 0; i < 100; i++)
		{
			float theta = 2.0f * 3.1415926f * float(i) / float(100);

			float x = r * cosf(theta);
			float y = r * sinf(theta);

			glVertex2f(x + x1, y + y1);

		}
		glEnd();
		if (xor) { glLogicOp(GL_COPY); glDisable(GL_LINE_STIPPLE); }
		break;
	}
	case 6:

		if (xor == true)
		{
			glLogicOp(GL_XOR);
			glLineStipple(3, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1);
		}
		else {
			glBegin(GL_LINE_LOOP);
			glColor3f(this->getColour().getRed(), this->getColour().getGreen(), this->getColour().getBlue());
		}


		glVertex2i(this->getPointA().getPointX(), this->getPointA().getPointY());
		glVertex2i(this->getPointA().getPointX() - ((this->getPointB().getPointX()) - (this->getPointA().getPointX())), this->getPointB().getPointY());
		glVertex2i(this->getPointB().getPointX(), this->getPointB().getPointY());
		glEnd();
		if (xor) { glLogicOp(GL_COPY); glDisable(GL_LINE_STIPPLE); }
		break;

	case 7:
	{

		int x1 = this->a.getPointX();
		int x2 = this->b.getPointX();
		int y1 = this->a.getPointY();
		int y2 = this->b.getPointY();

		float r = sqrt((((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2))));



		if (xor == true)
		{
			glLogicOp(GL_XOR);
			glLineStipple(3, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1);
		}
		else {
			glBegin(GL_LINE_LOOP);
			glColor3f(this->getColour().getRed(), this->getColour().getGreen(), this->getColour().getBlue());
		}

		for (int i = 0; i < 100; i++)
		{
			float theta = 2.0f * 3.1415926f * float(i) / float(100);

			float x = r * cosf(theta);
			float y = r * sinf(theta);

			glVertex2f(x + x1, y + y1);

		}
		glEnd();
		if (xor) { glLogicOp(GL_COPY); glDisable(GL_LINE_STIPPLE); }
		break;
	}




	}
}






void figure::printFigure()
{
	std::cout << a.getPointX() << std::endl;
	std::cout << a.getPointY() << std::endl;

	std::cout << b.getPointX() << std::endl;
	std::cout << b.getPointY() << std::endl;
}
figure::~figure()
{
}
;
