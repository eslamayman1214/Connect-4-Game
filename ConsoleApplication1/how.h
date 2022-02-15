#pragma once
#include<SFML/Graphics.hpp>


using namespace sf;
class how
{
public:
	how(float width, float height);
	~how();


	void draw(RenderWindow &window_how);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return select; }

private:
	int select;
	Font font;
	Text text_how[1];
};
