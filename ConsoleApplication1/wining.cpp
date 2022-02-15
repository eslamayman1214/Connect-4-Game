#include "wining.h"
#include <iostream>
#include <fstream>

using namespace std;
wining::wining(float width, float hight)
{
	if (!font.loadFromFile("font.otf")){
		//handle erorr
	}
	text_winner1[0].setFont(font);
	text_winner1[0].setColor(Color::Magenta);
	text_winner1[0].setStyle(Text::Style::Bold);
	text_winner1[0].setCharacterSize(20);
	text_winner1[0].setString("player 1 won");
	text_winner1[0].setPosition(Vector2f(60,200));

	text_winner1[1].setFont(font);
	text_winner1[1].setColor(Color::Magenta);
	text_winner1[1].setStyle(Text::Style::Bold);
	text_winner1[1].setCharacterSize(20);
	text_winner1[1].setString("moves");
	text_winner1[1].setPosition(Vector2f(80,290));

}


wining::~wining()
{
}
void wining::draw(RenderWindow &window_winner){

	for (int i = 0; i < 2; i++){
		window_winner.draw(text_winner1[i]);
	}
}

