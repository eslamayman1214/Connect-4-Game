#include "play.h"
#include <SFML/Graphics.hpp>

play::play(float width = 600, float height = 600)
{
	if (!font.loadFromFile("font.otf")){
		//handle erorr
	}

	text_play[0].setFont(font);
	text_play[0].setColor(Color::Red);
	text_play[0].setStyle(Text::Style::Bold);
	text_play[0].setCharacterSize(40);
	text_play[0].setString("single player");
	text_play[0].setPosition(Vector2f(width / 3.5, height / 4 * 1));

	text_play[1].setFont(font);
	text_play[1].setColor(Color::Blue);
	text_play[1].setStyle(Text::Style::Bold);
	text_play[1].setCharacterSize(40);
	text_play[1].setString("multi player");
	text_play[1].setPosition(Vector2f(width / 3.5, height / 4 * 2));

	text_play[2].setFont(font);
	text_play[2].setColor(Color::Blue);
	text_play[2].setStyle(Text::Style::Bold);
	text_play[2].setCharacterSize(40);
	text_play[2].setString("back");
	text_play[2].setPosition(Vector2f(width / 2.5, height / 4 * 3));

	select = 0;
}


play::~play()
{
}

void play::draw(RenderWindow &window_play){

	for (int i = 0; i < 3; i++){
		window_play.draw(text_play[i]);
	}
	
}

void play::MoveUp(){
	if (select - 1 >= 0){
		text_play[select].setColor(Color::Blue);
		select--;
		text_play[select].setColor(Color::Red);
	}
}
void play::MoveDown(){
	if (select + 1 < 3){
		text_play[select].setColor(Color::Blue);
		select++;
		text_play[select].setColor(Color::Red);
	}
}






