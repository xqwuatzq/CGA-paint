#include "colour.h"

colour::colour()
{
}

colour::colour(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}



colour::~colour()
{
}

float colour::getRed()
{
	return r;
}

float colour::getGreen()
{
	return g;
}

float colour::getBlue()
{
	return b;
}



