#include "single.h"
#include <SFML/Graphics.hpp>
single::single(float width = 600, float height = 600)
{
	if (!font.loadFromFile("font.otf")){
		//handle erorr
	}

	text_single[0].setFont(font);
	text_single[0].setColor(Color::Red);
	text_single[0].setStyle(Text::Style::Bold);
	text_single[0].setCharacterSize(40);
	text_single[0].setString("easy");
	text_single[0].setPosition(Vector2f(width / 2.5, height / 5 * 1));

	text_single[1].setFont(font);
	text_single[1].setColor(Color::Blue);
	text_single[1].setStyle(Text::Style::Bold);
	text_single[1].setCharacterSize(40);
	text_single[1].setString("medium");
	text_single[1].setPosition(Vector2f(width / 2.5, height / 5 * 2));

	text_single[2].setFont(font);
	text_single[2].setColor(Color::Blue);
	text_single[2].setStyle(Text::Style::Bold);
	text_single[2].setCharacterSize(40);
	text_single[2].setString("hard");
	text_single[2].setPosition(Vector2f(width / 2.5, height / 5 * 3));

	text_single[3].setFont(font);
	text_single[3].setColor(Color::Blue);
	text_single[3].setStyle(Text::Style::Bold);
	text_single[3].setCharacterSize(40);
	text_single[3].setString("back");
	text_single[3].setPosition(Vector2f(width / 2.5, height / 5 * 4));

	selecteditemindex = 0;
}


single::~single()
{
}

void single::draw(RenderWindow &window_menu){

	for (int i = 0; i < 4; i++){
		window_menu.draw(text_single[i]);
	}

}

void single::MoveUp(){
	if (selecteditemindex - 1 >= 0){
		text_single[selecteditemindex].setColor(Color::Blue);
		selecteditemindex--;
		text_single[selecteditemindex].setColor(Color::Red);
	}
}
void single::MoveDown(){
	if (selecteditemindex + 1 < 4){
		text_single[selecteditemindex].setColor(Color::Blue);
		selecteditemindex++;
		text_single[selecteditemindex].setColor(Color::Red);
	}
}