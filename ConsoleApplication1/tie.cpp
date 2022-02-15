#include "tie.h"
#include <sfml/Graphics.hpp>

anoos::anoos(float width , float height)
{
	if (!font.loadFromFile("font.otf")){
		//handle erorr
	}
	text_tie[0].setFont(font);
	text_tie[0].setColor(Color::Magenta);
	text_tie[0].setStyle(Text::Style::Bold);
	text_tie[0].setCharacterSize(30);
	text_tie[0].setString("tie");
	text_tie[0].setPosition(Vector2f(130,200));

	text_tie[1].setFont(font);
	text_tie[1].setColor(Color::Magenta);
	text_tie[1].setStyle(Text::Style::Bold);
	text_tie[1].setCharacterSize(20);
	text_tie[1].setString("moves of each 32");
	text_tie[1].setPosition(Vector2f(20,300));

	

	
}

anoos::~anoos()
{
}
void anoos::draw(RenderWindow &window_tie){

	for (int i = 0; i < 2; i++){
		window_tie.draw(text_tie[i]);
	}
}

