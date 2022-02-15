#pragma once
#include <sfml/Graphics.hpp>

using namespace sf;
class anoos
{
public:
	anoos(float width , float height);
	~anoos();

	void draw(RenderWindow &window_tie);
	
private:
	
	Font font;
	Text text_tie[2];
};

