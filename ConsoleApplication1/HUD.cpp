#include "HUD.h"

HUD::HUD()
{
	point p1, p2;

	colour grey = colour(0.33f, 0.33f, 0.33f);
	colour light_grey = colour(0.67f, 0.67f, 0.67f);
	colour black = colour(0, 0, 0);
	colour white = colour(1, 1, 1);
	colour magenta = colour(0.66f, 0.0f, 0.66f);
	colour light_magenta = colour(1.00f, 0.33f, 1.00f);
	colour blue = colour(0.0f, 0.0f, 0.67f);
	colour light_blue = colour(0.33f, 0.33f, 1.00f);
	colour green = colour(0.0f, 0.67f, 0.0f);
	colour light_green = colour(0.33f, 1.00f, 0.33f);
	colour red = colour(0.67f, 0.0f, 0.0f);
	colour light_red = colour(1.00f, 0.33f, 0.33f);
	colour yellow = colour(1.0f, 1.0f, 0.33f);
	colour cyan = colour(0.0f, 0.66f, 0.66f);
	colour light_cyan = colour(0.33f, 1.00f, 1.00f);
	colour brown = colour(0.67f, 0.33f, 0.0f);
	highlight = blue;
	lowlight = light_grey;

	selectedColour = white;
	selectedTool = LINE;

	p1.setX(PALETTE_X);
	p1.setY(WSIZEY);

	p2.setX(PALETTE_X + 70);
	p2.setY(0);


	//background da barra de ferramentas
	hudBackGroud1 = figure(p1, p2, light_grey, QUAD);


	//palette
	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 10);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 30);
	figure *colour1 = new figure(p1, p2, black, QUAD);
	figure *colour1_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 10);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 30);
	figure *colour2 = new figure(p1, p2, grey, QUAD);
	figure *colour2_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 40);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 60);
	figure *colour3 = new figure(p1, p2, blue, QUAD);
	figure *colour3_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 40);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 60);
	figure *colour4 = new figure(p1, p2, light_blue, QUAD);
	figure *colour4_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 70);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 90);
	figure *colour5 = new figure(p1, p2, green, QUAD);
	figure *colour5_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 70);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 90);
	figure *colour6 = new figure(p1, p2, light_green, QUAD);
	figure *colour6_b = new figure(p1, p2, black, QUAD_E);


	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 100);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 120);
	figure *colour7 = new figure(p1, p2, cyan, QUAD);
	figure *colour7_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 100);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 120);
	figure *colour8 = new figure(p1, p2, light_cyan, QUAD);
	figure *colour8_b = new figure(p1, p2, black, QUAD_E);


	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 130);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 150);
	figure *colour9 = new figure(p1, p2, red, QUAD);
	figure *colour9_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 130);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 150);
	figure *colour10 = new figure(p1, p2, light_red, QUAD);
	figure *colour10_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 160);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 180);
	figure *colour11 = new figure(p1, p2, magenta, QUAD);
	figure *colour11_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 160);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 180);
	figure *colour12 = new figure(p1, p2, light_magenta, QUAD);
	figure *colour12_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 190);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 210);
	figure *colour13 = new figure(p1, p2, brown, QUAD);
	figure *colour13_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 190);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 210);
	figure *colour14 = new figure(p1, p2, yellow, QUAD);
	figure *colour14_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 220);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 240);
	figure *colour15 = new figure(p1, p2, light_grey, QUAD);
	figure *colour15_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 220);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 240);
	figure *colour16 = new figure(p1, p2, white, QUAD);
	figure *colour16_b = new figure(p1, p2, black, QUAD_E);

	//indicador da cor selecionada
	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 250);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 290);
	drawColour = figure(p1, p2, selectedColour, QUAD);
	drawColour_b = figure(p1, p2, black, QUAD_E);


	//linha separadora
	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 300);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 300);
	s_line = figure(p1, p2, black, LINE);


	//toolbar
	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 310);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 330);
	figure *tool1 = new figure(p1, p2, light_grey, QUAD, LINE);
	figure *tool1_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 310);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 330);
	figure *tool2 = new figure(p1, p2, light_grey, QUAD, ERASE);
	figure *tool2_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 340);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 360);
	figure *tool3 = new figure(p1, p2, light_grey, QUAD, QUAD);
	figure *tool3_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 340);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 360);
	figure *tool4 = new figure(p1, p2, light_grey, QUAD, QUAD_E);
	figure *tool4_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 370);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 390);
	figure *tool5 = new figure(p1, p2, light_grey, QUAD, TRI);
	figure *tool5_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 370);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 390);
	figure *tool6 = new figure(p1, p2, light_grey, QUAD, TRI_E);
	figure *tool6_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 10);
	p1.setY(WSIZEY - 400);
	p2.setX(PALETTE_X + 30);
	p2.setY(WSIZEY - 420);
	figure *tool7 = new figure(p1, p2, light_grey, QUAD, CIRCLE);
	figure *tool7_b = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 40);
	p1.setY(WSIZEY - 400);
	p2.setX(PALETTE_X + 60);
	p2.setY(WSIZEY - 420);
	figure *tool8 = new figure(p1, p2, light_grey, QUAD, CIRCLE_E);
	figure *tool8_b = new figure(p1, p2, black, QUAD_E);

	//incons
	p1.setX(PALETTE_X + 26);
	p1.setY(WSIZEY - 314);
	p2.setX(PALETTE_X + 14);
	p2.setY(WSIZEY - 326);
	figure *icon1 = new figure(p1, p2, black, LINE);

	p1.setX(PALETTE_X + 44);
	p1.setY(WSIZEY - 314);
	p2.setX(PALETTE_X + 56);
	p2.setY(WSIZEY - 320);
	figure *icon2 = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 43);
	p1.setY(WSIZEY - 318);
	p2.setX(PALETTE_X + 56);
	p2.setY(WSIZEY - 326);
	figure *icon3 = new figure(p1, p2, black, QUAD);

	p1.setX(PALETTE_X + 12);
	p1.setY(WSIZEY - 342);
	p2.setX(PALETTE_X + 27);
	p2.setY(WSIZEY - 357);
	figure *icon4 = new figure(p1, p2, black, QUAD);

	p1.setX(PALETTE_X + 43);
	p1.setY(WSIZEY - 343);
	p2.setX(PALETTE_X + 57);
	p2.setY(WSIZEY - 357);
	figure *icon5 = new figure(p1, p2, black, QUAD_E);

	p1.setX(PALETTE_X + 20);
	p1.setY(WSIZEY - 372);
	p2.setX(PALETTE_X + 27);
	p2.setY(WSIZEY - 387);
	figure *icon6 = new figure(p1, p2, black, TRI);

	p1.setX(PALETTE_X + 50);
	p1.setY(WSIZEY - 372);
	p2.setX(PALETTE_X + 57);
	p2.setY(WSIZEY - 387);
	figure *icon7 = new figure(p1, p2, black, TRI_E);

	p1.setX(PALETTE_X + 20);
	p1.setY(WSIZEY - 410);
	p2.setX(PALETTE_X + 20);
	p2.setY(WSIZEY - 417);
	figure *icon8 = new figure(p1, p2, black, CIRCLE);


	p1.setX(PALETTE_X + 50);
	p1.setY(WSIZEY - 410);
	p2.setX(PALETTE_X + 50);
	p2.setY(WSIZEY - 417);
	figure *icon9 = new figure(p1, p2, black, CIRCLE_E);

	toolSelection = figure(p1, p2, blue, QUAD);

	//push para vector
	vecHUD.push_back(colour1);
	vecHUD.push_back(colour1_b);

	vecHUD.push_back(colour2);
	vecHUD.push_back(colour2_b);

	vecHUD.push_back(colour3);
	vecHUD.push_back(colour3_b);

	vecHUD.push_back(colour4);
	vecHUD.push_back(colour4_b);

	vecHUD.push_back(colour5);
	vecHUD.push_back(colour5_b);

	vecHUD.push_back(colour6);
	vecHUD.push_back(colour6_b);

	vecHUD.push_back(colour7);
	vecHUD.push_back(colour7_b);

	vecHUD.push_back(colour8);
	vecHUD.push_back(colour8_b);

	vecHUD.push_back(colour9);
	vecHUD.push_back(colour9_b);

	vecHUD.push_back(colour10);
	vecHUD.push_back(colour10_b);

	vecHUD.push_back(colour11);
	vecHUD.push_back(colour11_b);

	vecHUD.push_back(colour12);
	vecHUD.push_back(colour12_b);

	vecHUD.push_back(colour13);
	vecHUD.push_back(colour13_b);

	vecHUD.push_back(colour14);
	vecHUD.push_back(colour14_b);

	vecHUD.push_back(colour15);
	vecHUD.push_back(colour15_b);

	vecHUD.push_back(colour16);
	vecHUD.push_back(colour16_b);

	vecTOOL.push_back(tool1);
	vecTOOL.push_back(tool1_b);

	vecTOOL.push_back(tool1);
	vecTOOL.push_back(tool1_b);

	vecTOOL.push_back(tool2);
	vecTOOL.push_back(tool2_b);

	vecTOOL.push_back(tool3);
	vecTOOL.push_back(tool3_b);

	vecTOOL.push_back(tool4);
	vecTOOL.push_back(tool4_b);

	vecTOOL.push_back(tool5);
	vecTOOL.push_back(tool5_b);

	vecTOOL.push_back(tool6);
	vecTOOL.push_back(tool6_b);

	vecTOOL.push_back(tool7);
	vecTOOL.push_back(tool7_b);

	vecTOOL.push_back(tool8);
	vecTOOL.push_back(tool8_b);

	vecICON.push_back(icon1);
	vecICON.push_back(icon2);
	vecICON.push_back(icon3);
	vecICON.push_back(icon4);
	vecICON.push_back(icon5);
	vecICON.push_back(icon6);
	vecICON.push_back(icon7);
	vecICON.push_back(icon8);
	vecICON.push_back(icon9);
}

HUD::~HUD()
{

}

std::vector<figure*> HUD::getVectorPalette()
{
	return vecHUD;
}

std::vector<figure*> HUD::getVectorTool()
{
	return vecTOOL;
}

void HUD::setColour(colour _colour)
{
	selectedColour = _colour;
}

colour HUD::getColour()
{
	return selectedColour;
}

void HUD::setTool(int _tool)
{
	selectedTool = _tool;
}

int HUD::getTool()
{
	return selectedTool;
}

void HUD::drawHUD()
{
	point p1, p2;


	hudBackGroud1.desenharFigura(false);

	for (auto &e : vecHUD)
	{
		e->desenharFigura(false);
	}

	drawColour.setColour(selectedColour);
	drawColour_b.desenharFigura(false);
	drawColour.desenharFigura(false);
	s_line.desenharFigura(false);

	for (auto &e : vecTOOL)
	{
		if (e->getTool() == selectedTool && e->getTipo() != QUAD_E)
		{
			e->setColour(highlight);
		}
		else if (e->getTipo() != QUAD_E)
		{
			e->setColour(lowlight);
		}
		e->desenharFigura(false);
	}

	for (auto &e : vecICON)
	{
		e->desenharFigura(false);
	}
}

figure HUD::getBackground()
{
	return hudBackGroud1;
}
