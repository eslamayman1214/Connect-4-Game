#pragma once
#include<SFML/Graphics.hpp>


using namespace sf;
class menu
{
public:
	menu(float width,float height);
	~menu();


	void draw(RenderWindow &window_menu);
    void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selecteditemindex; }

private:
	int selecteditemindex;
	Font font;
	Text text_menu[4];
};

