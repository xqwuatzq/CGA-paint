#pragma once


#ifndef figura_h
#define figura_H


#include "point.h"
#include "colour.h"
#include <cmath>


class figure {
public:
	figure();
	figure(point _a, point _b, colour _cor, int type);
	figure(point _a, point _b, colour _cor, int type, int toolType);


	void setTipo(int);
	int getTipo();
	point getPointA();
	point getPointB();
	colour getColour();
	int getTool();
	void setColour(colour);
	void setPointA(int, int);
	void setPointB(int, int);


	void desenharFigura(bool xor);

	void printFigure();
	virtual ~figure();

protected:
	point a, b;
	int type;
	colour cor;
	int toolType;
};


#endif //!figura.h