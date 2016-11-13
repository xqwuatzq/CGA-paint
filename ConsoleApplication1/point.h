#pragma once

#ifndef point_h
#define point_h



#include <iostream>

class point
{
public:
	point();
	point(int _x, int _y);
	virtual ~point();

	int getPointX();
	int getPointY();

	void setX(int _X);
	void setY(int _Y);


protected:
	int x, y;
};


#endif // !point.h