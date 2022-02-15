#pragma once
#include<SFML/Graphics.hpp>


using namespace sf;
class play
{
public:
	play(float width, float height);
	~play();


	void draw(RenderWindow &window_play);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return select; }

private:
	int select;
	Font font;
	Text text_play[3];
};
