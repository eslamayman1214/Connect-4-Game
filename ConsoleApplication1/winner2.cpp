#include "winner2.h"


winner2::winner2(float width , float height)
{
	if (!font.loadFromFile("font.otf")){
		//handle erorr
	}

	text_winner2[0].setFont(font);
	text_winner2[0].setColor(Color::Magenta);
	text_winner2[0].setStyle(Text::Style::Bold);
	text_winner2[0].setCharacterSize(20);
	text_winner2[0].setString("player 2 won");
	text_winner2[0].setPosition(Vector2f(60,200));

	text_winner2[1].setFont(font);
	text_winner2[1].setColor(Color::Magenta);
	text_winner2[1].setStyle(Text::Style::Bold);
	text_winner2[1].setCharacterSize(20);
	text_winner2[1].setString("moves  ");
	text_winner2[1].setPosition(Vector2f(80,290));

}


winner2::~winner2()
{
}
void winner2::draw(RenderWindow &window_winner2){

	for (int i = 0; i < 2; i++){
		window_winner2.draw(text_winner2[i]);
	}
}


