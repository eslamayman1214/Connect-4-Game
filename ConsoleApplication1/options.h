#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class options
{
public:
	options(float width,float height);

	
	~options();
	void draw(RenderWindow &window_option);
	void MoveUp();
	void MoveDown();
	
	int GetPressedItem() { return selecteditemindex; }
private:
	int selecteditemindex;
	Font font;
	Text text_option[4];
};

