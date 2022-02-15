#include "how.h"
#include <SFML/Graphics.hpp>

how::how(float width = 800, float height = 600)

{
	if (!font.loadFromFile("font.otf")){
		//handle erorr
	}
	text_how[0].setFont(font);
	text_how[0].setColor(Color::Red);
	text_how[0].setStyle(Text::Style::Bold);
	text_how[0].setCharacterSize(40);
	text_how[0].setString("back");
	text_how[0].setPosition(Vector2f(width / 2.5, height / 2 * 1.80));



	select = 0;
}
how::~how()
{
}

void how::draw(RenderWindow &window_how){

	for (int i = 0; i < 1; i++){
		window_how.draw(text_how[i]);
	}

}