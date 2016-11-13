#pragma once


#ifndef colour_h
#define colour_h

class colour
{
public:
	colour();
	colour(float _r, float _g, float _b);
	virtual ~colour();


	float getRed();
	float getGreen();
	float getBlue();




protected:
	float r, g, b;
};




#endif // !colour_h
