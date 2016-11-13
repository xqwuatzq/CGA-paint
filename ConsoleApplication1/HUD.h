#pragma once

#ifndef HUD_H
#define HUD_H



#include <vector>
#include "figura.h"


#define WSIZEY 600			//tamanho Y da janela
#define WSIZEX 1000			//tamanho X da janela

#define PALETTE_X 0			//posicao da palette

#define QUAD 1				//quadrados/rectangulos
#define LINE 2				//linhas
#define TRI  3				//triangulos
#define QUAD_E 4			//quadrados/rectangulos vazios
#define CIRCLE 5			//circulos
#define TRI_E 6				//triangulos vazios
#define CIRCLE_E 7			//circulos vazios
#define ERASE 9				//apagar



class HUD
{
public:
	HUD();

	virtual ~HUD();

	std::vector<figure *> getVectorPalette();
	std::vector<figure *> getVectorTool();
	void setColour(colour);
	colour getColour();
	void setTool(int);
	int getTool();
	void drawHUD();
	figure getBackground();


protected:
	std::vector<figure *> vecHUD;
	std::vector<figure *> vecTOOL;
	std::vector<figure *> vecICON;

	colour selectedColour, highlight, lowlight;
	int selectedTool;
	figure drawColour, drawColour_b, hudBackGroud1, s_line, toolSelection;

};




#endif // !HUD_H