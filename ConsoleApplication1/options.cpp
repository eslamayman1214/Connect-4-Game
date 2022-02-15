#include "options.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

options::options(float width=800,float height=600)
{
	
		if (!font.loadFromFile("font.otf")){
			//handle erorr
		}
		text_option[0].setFont(font);
		text_option[0].setColor(Color::Red);
		text_option[0].setStyle(Text::Style::Bold);
		text_option[0].setCharacterSize(40);
		text_option[0].setString("sound mute ");
		text_option[0].setPosition(Vector2f(width / 3.5, height / 5 * 1));

		text_option[1].setFont(font);
		text_option[1].setColor(Color::Blue);
		text_option[1].setStyle(Text::Style::Bold);
		text_option[1].setCharacterSize(40);
		text_option[1].setString("sound unmute ");
		text_option[1].setPosition(Vector2f(width / 3.5, height / 5 * 2));

		text_option[2].setFont(font);
		text_option[2].setStyle(Text::Style::Bold);
		text_option[2].setCharacterSize(40);
		text_option[2].setColor(Color::Blue);
		text_option[2].setString("how to play");
		text_option[2].setPosition(Vector2f(width / 3.5, height / 5 * 3));

		text_option[3].setFont(font);
		text_option[3].setColor(Color::Blue);
		text_option[3].setStyle(Text::Style::Bold);
		text_option[3].setCharacterSize(40);
		text_option[3].setString("back");
		text_option[3].setPosition(Vector2f(width / 2.5, height / 5 * 4));

		selecteditemindex = 0;
}


options::~options()
{
}
void options::draw(RenderWindow &window_option){

	for (int i = 0; i < 4; i++){
		window_option.draw(text_option[i]);
	}

}
void options::MoveUp(){
	if (selecteditemindex - 1 >= 0){
		text_option[selecteditemindex].setColor(Color::Blue);
		selecteditemindex--;
		text_option[selecteditemindex].setColor(Color::Red);
	}
}
void options::MoveDown(){
	if (selecteditemindex + 1 < 4){
		text_option[selecteditemindex].setColor(Color::Blue);
		selecteditemindex++;
		text_option[selecteditemindex].setColor(Color::Red);
	}
}