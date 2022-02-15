#pragma once
#include<sfml/Graphics.hpp>

using namespace sf;
class wining
{
public:
	wining(float width,float hight);
	~wining();

	void draw(RenderWindow &window_winner);

	
private:

	Font font;
	Text text_winner1[2];

};

