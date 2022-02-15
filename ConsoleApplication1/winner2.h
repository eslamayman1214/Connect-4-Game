#pragma once
#include<sfml/Graphics.hpp>

using namespace sf;
class winner2
{
public:
	winner2(float width,float height);
	~winner2();

	void draw(RenderWindow &window_winner2);


private:
	
	Font font;
	Text text_winner2[2];
};

