#pragma once
#include<SFML/Graphics.hpp>


using namespace sf;
class single
{
public:
	single(float width, float height);
	~single();


	void draw(RenderWindow &window_single);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selecteditemindex; }

private:
	int selecteditemindex;
	Font font;
	Text text_single[4];
};

