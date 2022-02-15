#include "menu.h"
#include <SFML/Graphics.hpp>
menu::menu(float width,float height)
{
	if (!font.loadFromFile("font.otf")){
		//handle erorr
	}
	text_menu[0].setFont(font);
	text_menu[0].setColor(Color::Transparent);
	text_menu[0].setString("connect four");
	text_menu[0].setCharacterSize(50);
	text_menu[0].setStyle(Text::Style::Italic|Text::Style::Bold);
	//text_menu[0].setOutlineColor(Color::Black);
	//text_menu[0].setOutlineThickness(7);
	text_menu[0].setPosition(Vector2f(width / 5, height / 5 * 1));

	text_menu[1].setFont(font);
	text_menu[1].setColor(Color::Red);
	text_menu[1].setStyle(Text::Style::Bold);
	text_menu[1].setCharacterSize(40);
	text_menu[1].setString("play");
	text_menu[1].setPosition(Vector2f(width / 2.5, height / 5 * 2));

	text_menu[2].setFont(font);
	text_menu[2].setColor(Color::Blue);
	text_menu[2].setStyle(Text::Style::Bold);
	text_menu[2].setCharacterSize(40);
	text_menu[2].setString("options");
	text_menu[2].setPosition(Vector2f(width / 2.5, height / 5 * 3));

	text_menu[3].setFont(font);
	text_menu[3].setColor(Color::Blue);
	text_menu[3].setStyle(Text::Style::Bold);
	text_menu[3].setCharacterSize(40);
	text_menu[3].setString("exit");
	text_menu[3].setPosition(Vector2f(width / 2.5, height / 5 * 4));
	
	
	
	selecteditemindex = 1;
}


menu::~menu()
{
}

void menu::draw(RenderWindow &window_menu){
	
	for (int i = 0; i < 4; i++){
		window_menu.draw(text_menu[i]);
	}

	}
void menu::MoveUp(){
	if (selecteditemindex - 1 > 0){
		text_menu[selecteditemindex].setColor(Color::Blue);
		selecteditemindex--;
		text_menu[selecteditemindex].setColor(Color::Red);
	}
}
void menu::MoveDown(){
	if (selecteditemindex + 1 < 4){
		text_menu[selecteditemindex].setColor(Color::Blue);
		selecteditemindex++;
		text_menu[selecteditemindex].setColor(Color::Red);
	}
}
