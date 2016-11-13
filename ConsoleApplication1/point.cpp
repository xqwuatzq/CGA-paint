#include "point.h"



point::point()
{
}

point::point(int _x, int _y)
{
	x = _x;
	y = _y;
}


point::~point()
{
}

int point::getPointX()
{
	return x;
}

int point::getPointY()
{
	return y;
}

void point::setX(int _x)
{
	x = _x;
}

void point::setY(int _Y)
{
	y = _Y;
}


