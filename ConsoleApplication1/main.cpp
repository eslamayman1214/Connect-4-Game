#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "menu.h"
#include "play.h"
#include "options.h"
#include "single.h"
#include "how.h"
#include "wining.h"
#include "winner2.h"
#include "tie.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using namespace sf;

int column;
int board[100][100];

RenderWindow window_single, window_option, window_play, window_how, window, window_winner, window_winner2, window_medium, window_multi, window_tie, window_hard;
RenderWindow window_menu(VideoMode(800, 600), " connect four ");

int j = 0;
bool who_will_play = 0;
Event evnt;
short move1 = 0;
short move2 = 0;
int k = 0;
int c = 0;
int d = 0;
int z = 0;
int player = 3;
int playy = 0;
Sprite player1[33];
Sprite player2[33];
bool is_valled(int xxx, int yyy)
{
	if (xxx <= 7 && yyy <= 7 && xxx >= 0 && yyy >= 0) return true;
	else   return false;
}
vector<int> check_left_diagonal(int xx, int yy, int player)
{
	int numleft = 0, numright = 0;
	for (int right = 0; right <= 7; right++)
	{
		if (board[xx + right][yy + right] == player)
			numright++;
		else break;
	}
	for (int left = 1; left <= 7; left++)
	{
		if (board[xx - left][yy - left] == player)
			numleft++;
		else break;
	}
	vector<int>v(2);
	v[0] = numleft;
	v[1] = numright;
	return v;
}
vector<int> check_right_diagonal(int xx, int yy, int player)
{
	int numleft = 0, numright = 0;
	for (int right = 0; right <= 7; right++)
	{
		if (board[xx - right][yy + right] == player)
			numright++;
		else break;
	}
	for (int left = 1; left <= 7; left++)
	{
		if (board[xx + left][yy - left] == player)
			numleft++;
		else break;
	}
	vector<int>v(2);
	v[0] = numleft;
	v[1] = numright;
	return v;
}

int check_ddown(int xx, int yy, int player)
{
	int numdown = 0;
	for (int down = 0; down <= 7; down++)
	{
		if (board[xx + down][yy] == player)
			numdown++;
		else break;
	}
	return numdown;
}
vector<int> check_Right_Left(int xx, int yy, int player)
{
	int numright = 0, numleft = 0;

	for (int Left = 0; Left <= 7; Left++)
	{
		if (board[xx][yy - Left] == player)
			numleft++;
		else
			break;
	}
	for (int right = 1; right <= 7; right++)
	{
		if (board[xx][yy + right] == player)
			numright++;
		else
			break;
	}
	vector<int>v(2);
	v[0] = numleft;
	v[1] = numright;
	return v;
}/*
 void suggest(){
 for (int i = 0; i < 8; i++)
 {
 for (int j = 0; j < 8; j++)
 {
 if (board[i][j] == 0)
 {
 "cell[i][j] ";
 }
 }
 }
 }*/

int x, y, a, b;
int boaard[10][10];

int visited[100][100];
////////////////////////////////////////////////////////////////////////horizontal//////////////////////////////////////////////////////////////
vector<int>horizontal(int player)
{
	vector<int>v(2);
	for (int row = 7; row >= 0; row--)
	{
		for (int col = 0; col <= 4; col++)
		{
			if (board[row][col] == board[row][col + 1] &&
				board[row][col] == board[row][col + 2] &&
				board[row][col] == player && visited[row][col] == 0)
			{
				v[0] = row;
				v[1] = col;
				visited[row][col] = 1;
				return v;
			}
		}
	}
	v[0] = -1;
	v[1] = -1;
	return v;
}
///////////////////////////////////////////////////////////////////////////vertical/////////////////////////////////////////////////////////////////
vector<int>vertical(int player)
{
	vector<int>v(2);
	for (int col = 7; col >= 0; col--)
	{
		for (int row = 7; row >= 3; row--)
		{
			if (board[row][col] == board[row - 1][col] &&
				board[row][col] == board[row - 2][col] &&
				board[row][col] == player && visited[row][col] == 0)
			{
				v[0] = row;
				v[1] = col;
				visited[row][col] = 1;
				return v;
			}
		}
	}
	v[0] = -1;
	v[1] = -1;
	return v;

}
////////////////////////////////////////////////////////////////rd/////////////////////////////////////////////////////////////////


vector<int>rd(int player)
{
	vector<int>v(2);
	for (int row = 7; row >= 3; row--)
	{
		for (int col = 0; col <= 5; col++)
		{
			if (board[row][col] == board[row - 1][col + 1] &&
				board[row - 1][col + 1] == board[row - 2][col + 2] &&
				board[row][col] == player && visited[row][col] == 0)
			{
				v[0] = row;
				v[1] = col;
				visited[row][col] = 1;
				return v;
			}
		}
		v[0] = -1;
		v[1] = -1;
		return v;
	}
}


//////////////////////////////////////////////////////ld//////////////////////////////////////////////////////////////////////////

vector<int>ld(int player)
{
	vector<int>v(2);
	for (int row = 7; row >= 3; row--)
	{
		for (int col = 7; col >= 3; col--)
		{
			if (board[row][col] == board[row - 1][col - 1] &&
				board[row - 1][col - 1] == board[row - 2][col - 2] &&
				board[row][col] == player && visited[row][col] == 0)
			{
				v[0] = row;
				v[1] = col;
				visited[row][col] = 1;
				return v;
			}
		}
		v[0] = -1;
		v[1] = -1;
		return v;
	}
}

int main()
{

	ifstream ingame;
	ingame.open("games.txt");

	int row = 0;
	int win = 0;
	int games;
	int numbers;
	int count = 0;
	while (!ingame.eof()) {
		ingame >> games;
		count++;
	}

	ingame.close();
	ofstream outgame;
	outgame.open("games.txt");
	Text text_leader1[100];
	Text text_leader2[100];
	Text text_playerwon[100];
	Text text_player2won[100];

	// Definition of Windows 

	menu text_menu(800, 600);
	play text_play(800, 600);
	options text_option(800, 600);
	single text_single(800, 600);
	how text_how(800, 600);
	wining text_winner1(300, 600);
	winner2 text_winner2(300, 600);
	anoos text_tie(300, 600);

	RectangleShape line;
	line.setSize(Vector2f(200, 3));
	line.setPosition(Vector2f(50, 250));
	line.setFillColor(Color::Green);

	RectangleShape line2;
	line2.setSize(Vector2f(200, 3));
	line2.setPosition(Vector2f(50, 350));
	line2.setFillColor(Color::Green);

	//if play ==0    THAT MEAN TIE
	//IF PLAY ==1    THAT MEAN PLAYER 1 WON 
	//IF PLAY ==2    THAT MEAN PLAYER 2 WON 

	//1  indicates to that pc should play 
	//0  indicates to that player 1  should play  

	Texture board_texture;
	if (!board_texture.loadFromFile("UTT.png"))
	{
		cout << "errorr" << endl;
	}

	Texture player1_texture;
	if (!player1_texture.loadFromFile("chance1.PNG"))
	{
		cout << "errorr" << endl;
	}
	Texture player2_texture;
	if (!player2_texture.loadFromFile("chance2.PNG"))
	{
		cout << "errorr" << endl;
	}
	Texture single_texture, play_texture, menu_texture;
	if (!single_texture.loadFromFile("single image.jpg")) {
		cout << "error on single image " << endl;
	}
	if (!play_texture.loadFromFile("play image.jpg")) {
		cout << "error on play image " << endl;
	}
	if (!menu_texture.loadFromFile("islaam.jpg")) {
		cout << "error on menu image " << endl;
	}

	Sprite background_board1, single_sprite, play_sprite, menu_sprite;
	player1[0].setTexture(player1_texture);
	background_board1.setTexture(board_texture);
	player1[0].setPosition(Vector2f(325, 365));
	background_board1.setScale(Vector2f(0.98, 1.28));
	single_sprite.setTexture(single_texture);
	play_sprite.setTexture(play_texture);
	menu_sprite.setTexture(menu_texture);

	Texture texture1;
	if (!texture1.loadFromFile("UTT.png")) { cout << "Error loading Background !\n"; }

	Sprite sprite1;
	sprite1.setTexture(texture1);
	sprite1.setScale(Vector2f(0.98, 1.28));
	Texture texture2;
	if (!texture2.loadFromFile("chance1.png")) cout << "Error loading Player(1) !\n";
	Sprite sprite2[33];
	sprite2[0].setTexture(texture2);
	sprite2[0].setPosition(Vector2f(325, 365));
	Texture texture3;
	if (!texture3.loadFromFile("chance2.png")) cout << "Error loading Player(2) !\n";
	Sprite sprite3[33];

	// Texture ("Background")

	Texture texture;
	if (!texture.loadFromFile("background.jpg"))
	{
		//erorr
	}
	Sprite sprite;
	sprite.setTexture(texture);

	// Texture ("How to play")

	Texture texture_how;
	if (!texture_how.loadFromFile("how to play.jpg")) {
		cout << "error " << endl;
	}
	Sprite sprite_how;
	sprite_how.setTexture(texture_how);



	// Menu Music

	Music music, music_play;
	if (!music.openFromFile("Maxime Abbey - Arabian Feelings.ogg")) {
		cout << " error " << endl;
	}
	music.play();
	music.setVolume(25);
	music.setLoop(true);

	music_play.openFromFile("Free to Fly.ogg");
	music_play.setVolume(25);
	music.setLoop(true);

	SoundBuffer buffer, buffer_hit, buffer_win;
	if (!buffer.loadFromFile("click.wav")) {
		cout << "error " << endl;
	}
	if (!buffer_hit.loadFromFile("coin hit.wav")) {
		cout << "error on coin hit" << endl;
	}
	if (!buffer_win.loadFromFile("winning sound.wav")) {
		cout << "error on winning sound" << endl;
	}
	Sound click, coin_hit, winning;
	click.setBuffer(buffer);
	coin_hit.setBuffer(buffer_hit);
	winning.setBuffer(buffer_win);

	Clock clock;

	Font font;
	font.loadFromFile("font.otf");
	Text move1text, move2text, timetext;

	move1text.setFont(font);
	move1text.setColor(Color::Red);
	move1text.setPosition(200, 280);

	move2text.setFont(font);
	move2text.setColor(Color::Red);
	move2text.setPosition(200, 280);

	while (window.isOpen() || window_winner.isOpen() || window_menu.isOpen() || window_play.isOpen() || window_how.isOpen() || window_single.isOpen() || window_option.isOpen() || window_winner.isOpen() || window_winner2.isOpen() || window_medium.isOpen() || window_multi.isOpen() || window_tie.isOpen() || window_hard.isOpen())
	{
		while (window_winner.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_winner.close();
				window.close();
				window_medium.close();
				window_hard.close();
				window_multi.close();
			}
		}
		window_winner.clear();
		window_winner.draw(single_sprite);
		text_winner1.draw(window_winner);
		window_winner.draw(line);
		window_winner.draw(line2);
		window_winner.draw(move1text);
		window_winner.display();

		while (window_winner2.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_winner2.close();
				window.close();
				window_medium.close();
				window_hard.close();
				window_multi.close();
			}
		}

		window_winner2.clear();
		window_winner2.draw(single_sprite);
		text_winner2.draw(window_winner2);
		window_winner2.draw(line);
		window_winner2.draw(move2text);
		window_winner2.draw(line2);
		window_winner2.display();

		while (window_tie.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_tie.close();
				window.close();
				window_medium.close();
				window_hard.close();
				window_multi.close();
			}
		}
		window_tie.clear();
		window_tie.draw(single_sprite);
		text_tie.draw(window_tie);
		window_tie.draw(line);
		window_tie.draw(line2);
		window_tie.display();

		while (window_menu.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_menu.close();
			}
			switch (evnt.type) {
			case Event::KeyPressed:
				switch (evnt.key.code) {
				case Keyboard::Up:
					text_menu.MoveUp();
					click.play();
					break;
				case Keyboard::Down:
					text_menu.MoveDown();
					click.play();
					break;

				case Keyboard::Enter:
					click.play();
					switch (text_menu.GetPressedItem()) {
					case 1:
						window_play.create(VideoMode(800, 600), "connect 4");
						window_play.setMouseCursorVisible(false);
						window_menu.close();
						break;
					case 2:
						window_option.create(VideoMode(800, 600), "option");
						window_option.setMouseCursorVisible(false);
						window_menu.close();
						break;
					case 3:
						window_menu.close();
						break;
					}
				}

			}
		}
		window_menu.clear();
		window_menu.draw(menu_sprite);
		text_menu.draw(window_menu);
		window_menu.display();

		while (window_play.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_play.close();
			}
			switch (evnt.type) {
			case Event::KeyPressed:
				switch (evnt.key.code) {
				case Keyboard::Up:
					text_play.MoveUp();
					click.play();
					break;
				case Keyboard::Down:
					text_play.MoveDown();
					click.play();
					break;

				case Keyboard::Enter:
					click.play();
					switch (text_play.GetPressedItem()) {
					case 0:
						window_single.create(VideoMode(800, 600), "single level");
						window_single.setMouseCursorVisible(false);
						window_play.close();
						break;
					case 1:
						window_multi.create(VideoMode(1024, 1250), "Connect Four");
						window_play.close();
						music.stop();
						music_play.play();
						break;
					case 2:
						window_menu.create(VideoMode(800, 600), "connect four");
						window_menu.setMouseCursorVisible(false);
						window_play.close();
						break;

					}
				}

			}
		}

		window_play.clear();
		window_play.draw(play_sprite);
		text_play.draw(window_play);
		window_play.display();

		while (window_option.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_option.close();
			}
			switch (evnt.type) {
			case Event::KeyPressed:
				switch (evnt.key.code) {
				case Keyboard::Up:
					text_option.MoveUp();
					click.play();
					break;
				case Keyboard::Down:
					text_option.MoveDown();
					click.play();
					break;
				case Keyboard::Enter:
					click.play();
					switch (text_option.GetPressedItem()) {
					case 0:
						music.pause();
						break;
					case 1:
						music.play();
						break;
					case 2:
						window_how.create(VideoMode(800, 600), "how to play");
						window_how.setMouseCursorVisible(false);
						window_option.close();
						break;
					case 3:
						window_menu.create(VideoMode(800, 600), "connect four ");
						window_menu.setMouseCursorVisible(false);
						window_option.close();

					}
				}

			}
		}
		window_option.clear();
		window_option.draw(play_sprite);
		text_option.draw(window_option);
		window_option.display();

		while (window_single.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_single.close();
			}
			switch (evnt.type) {
			case Event::KeyPressed:
				switch (evnt.key.code) {
				case Keyboard::Up:
					text_single.MoveUp();
					click.play();
					break;
				case Keyboard::Down:
					text_single.MoveDown();
					click.play();
					break;
				case Keyboard::Enter:
					switch (text_single.GetPressedItem()) {
					case 0:
						window.create(VideoMode(1024, 1250), "connect Four");
						window.setMouseCursorVisible(false);
						music.stop();
						music_play.play();
						window_single.close();

						break;
					case 1:
						window_medium.create(VideoMode(1024, 1200), "connect Four");
						window_medium.setMouseCursorVisible(false);
						music.stop();
						music_play.play();
						window_single.close();
						break;
					case 2:
						window_hard.create(VideoMode(1024, 1250), "Hard level");
						music.stop();
						music_play.play();
						window_single.close();
						break;
					case 3:
						window_play.create(VideoMode(800, 600), "connect four ");
						window_play.setMouseCursorVisible(false);
						window_single.close();
						break;

					}
				}

			}
		}

		window_single.clear();
		window_single.draw(single_sprite);
		text_single.draw(window_single);
		window_single.display();
		while (window_how.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window_how.close();
			}
			switch (evnt.type) {
			case Event::KeyPressed:
				switch (evnt.key.code) {
				case Keyboard::Enter:
					click.play();
					switch (text_how.GetPressedItem()) {
					case 0:
						window_option.create(VideoMode(800, 600), "connect four ");
						window_option.setMouseCursorVisible(false);
						window_how.close();
						break;
					}
				}
			}
		}

		window_how.clear();
		window_how.draw(sprite_how);
		text_how.draw(window_how);
		window_how.display();
		///////////////////////////////////////////////////////////Easy/////////////////////////////////////////////////////////////////
		while (window.pollEvent(evnt))
		{

			if (evnt.type == Event::Closed) {
				window.close();
			}
			if (playy == 0)
			{
				switch (evnt.type)
				{

				case Event::Closed:
					window.close();
					break;

				case Event::KeyPressed:
					switch (evnt.key.code)
					{
					case Keyboard::Right:
						if (column + 1 < 8)
						{
							column++; player1[j].move(Vector2f(57.5, 0));
						}
						break;
					case Keyboard::Left:
						if (column - 1 >= 0)
						{
							column--; player1[j].move(Vector2f(-57.5, 0));
						}
						break;
					case Keyboard::Enter:
						if (who_will_play == 0)
						{
							for (int first_empty_row_from_below = 7; first_empty_row_from_below >= 0; first_empty_row_from_below--)
							{
								if (board[first_empty_row_from_below][column] == 0)
								{
									who_will_play = 1;
									board[first_empty_row_from_below][column] = 1;
									player1[j].move(Vector2f(0, (first_empty_row_from_below + 1) * 70));
									coin_hit.play();
									move1++;
									if (check_ddown(first_empty_row_from_below, column, 1) == 4 || check_right_diagonal(first_empty_row_from_below, column, 1)[0] + check_right_diagonal(first_empty_row_from_below, column, 1)[1] == 4 || check_left_diagonal(first_empty_row_from_below, column, 1)[0] + check_left_diagonal(first_empty_row_from_below, column, 1)[1] == 4 || check_Right_Left(first_empty_row_from_below, column, 1)[0] + check_Right_Left(first_empty_row_from_below, column, 1)[1] == 4)
									{
										playy = 1;
										window_winner.create(VideoMode(300, 600), "winner");
										music_play.stop();
										winning.play();
									}
									break;
								}
							}
						}

						while (who_will_play && playy == 0)
						{
							column = 0;
							int random_column = rand() % 8;
							player2[j].setTexture(player2_texture);
							player2[j].setPosition(Vector2f(325, 365));

							for (int first_empty_row_from_below = 7; first_empty_row_from_below >= 0; first_empty_row_from_below--)
							{
								if (board[first_empty_row_from_below][random_column] == 0)
								{
									board[first_empty_row_from_below][random_column] = 2;
									who_will_play = 0;
									move2++;
									if (check_ddown(first_empty_row_from_below, random_column, 2) == 4 || check_right_diagonal(first_empty_row_from_below, random_column, 2)[0] + check_right_diagonal(first_empty_row_from_below, random_column, 2)[1] == 4 || check_left_diagonal(first_empty_row_from_below, random_column, 2)[0] + check_left_diagonal(first_empty_row_from_below, random_column, 2)[1] == 4 || check_Right_Left(first_empty_row_from_below, random_column, 2)[0] + check_Right_Left(first_empty_row_from_below, random_column, 2)[1] == 4)
									{
										playy = 1;
										window_winner2.create(VideoMode(300, 600), "winner");
										music_play.stop();
										winning.play();
									}

									player2[j].move(sf::Vector2f(57.5 * (random_column), (first_empty_row_from_below + 1) * 70));
									if (playy == 0)
									{
										j++;
										player1[j].setTexture(player1_texture);
										player1[j].setPosition(sf::Vector2f(325, 365));
									}
									break;
								}
							}
						}
						break;
					}
					break;
				}
			}
			if (playy == 0 && j >= 32) {
				window_tie.create(VideoMode(300, 600), "Tie Case");
				window_medium.close();
				window_multi.close();
				music_play.stop();
				winning.play();
				games++;
				playy = 1;
			}
			// counting move 1

			window.clear();
			window.draw(background_board1);

			for (int i = 0; i <= j && i <= 31; i++)
			{
				window.draw(player1[i]);
				window.draw(player2[i]);
			}
			window.display();

		}
		///////////////////////////////////////////////mediuuuuuuuuuuummmmmmm//////////////////////////////////////////////////////////////
		while (window_medium.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window_medium.close();
				break;
				if (playy == 0)
				{
			case sf::Event::KeyPressed:
				switch (evnt.key.code)
				{
				case Keyboard::Right:
					if (column + 1 <= 7)
					{
						column++; player1[j].move(sf::Vector2f(57.5, 0));
					}
					break;
				case sf::Keyboard::Left:
					if (column - 1 >= 0)
					{
						column--; player1[j].move(sf::Vector2f(-57.5, 0));
					}
					break;
				case sf::Keyboard::Enter:
					while (who_will_play == 0)
					{
						for (int first_empty_row_from_below = 7; first_empty_row_from_below >= 0; first_empty_row_from_below--)
						{
							if (board[first_empty_row_from_below][column] == 0)
							{
								who_will_play = 1;
								board[first_empty_row_from_below][column] = 1;
								row = first_empty_row_from_below;
								player1[j].move(sf::Vector2f(0, (first_empty_row_from_below + 1) * 70));
								coin_hit.play();
								move1++;
								if (check_ddown(first_empty_row_from_below, column, 1) == 4 || check_right_diagonal(first_empty_row_from_below, column, 1)[0] + check_right_diagonal(first_empty_row_from_below, column, 1)[1] == 4 || check_left_diagonal(first_empty_row_from_below, column, 1)[0] + check_left_diagonal(first_empty_row_from_below, column, 1)[1] == 4 || check_Right_Left(first_empty_row_from_below, column, 1)[0] + check_Right_Left(first_empty_row_from_below, column, 1)[1] == 4)
								{
									playy = 1;
									j++;
									window_winner.create(VideoMode(300, 600), "winner");
									music_play.stop();
									winning.play();
								}
								break;
							}
						}
					}
					break;
				}
				if (who_will_play == 1)
				{

					if (check_left_diagonal(row, column, 1)[0] + check_right_diagonal(row, column, 1)[1] == 3)
					{
						vector<int> return_val = check_right_diagonal(row, column, 1);
						return_val[1]--;
						if (is_valled(row + return_val[1] + 1, column + return_val[1] + 1) == true)
						{
							if (board[row + return_val[1] + 1][column + return_val[1] + 1] == 0 && board[row + return_val[1]][column + return_val[1] + 1] != 0)
							{
								who_will_play = 0;
								board[row + return_val[1] + 1][column + return_val[1] + 1] = 2;
								player2[j].setTexture(player2_texture);
								player2[j].setPosition(sf::Vector2f(325, 365));
								player2[j].move(sf::Vector2f((column + return_val[1] + 1) * 57.5, 70 * (return_val[1] + 2 + row)));
								j++;
								player1[j].setTexture(player1_texture);
								player1[j].setPosition(sf::Vector2f(325, 365));
								coin_hit.play();
								move2++;
								column = 0; row = 0;
								cout << "left diagonal \n";
							}
						}
					}

					else if (check_right_diagonal(row, column, 1)[0] + check_right_diagonal(row, column, 1)[1] == 3)
					{
						vector<int> return_val = check_right_diagonal(row, column, 1);
						return_val[1]--;
						if (is_valled(row - return_val[1] - 1, column + return_val[1] + 1) == true)
						{
							if (board[row - return_val[1] - 1][column + return_val[1] + 1] == 0 && board[row - return_val[1]][column + return_val[1] + 1] != 0)
							{
								who_will_play = 0;
								board[row - return_val[1] - 1][column + return_val[1] + 1] = 2;
								player2[j].setTexture(player2_texture);
								player2[j].setPosition(sf::Vector2f(325, 365));
								player2[j].move(sf::Vector2f((column + return_val[1] + 1) * 57.5, 70 * (row)));
								j++;
								move2++;
								player1[j].setTexture(player1_texture);
								player1[j].setPosition(sf::Vector2f(325, 365));
								column = 0; row = 0;
								cout << "right diagonal \n";

							}
						}
					}
					else  if (check_ddown(row, column, 1) == 3 && row > 0)
					{
						who_will_play = 0;
						board[row - 1][column] = 2;
						player2[j].setTexture(player2_texture);
						player2[j].setPosition(sf::Vector2f(325, 365));
						player2[j].move(sf::Vector2f(column * 57.5, 70 * (row)));
						j++;
						move2++;
						player1[j].setTexture(player1_texture);
						player1[j].setPosition(sf::Vector2f(325, 365));
						column = 0; row = 0;
						cout << " ddown  \n";

					}

					else if (check_Right_Left(row, column, 1)[0] + check_Right_Left(row, column, 1)[1] == 3)
					{
						vector<int> return_val = check_Right_Left(row, column, 1);
						if (is_valled(row, column + return_val[1] + 1) == true)
						{
							if (board[row][column + return_val[1] + 1] == 0 && board[row + 1][column + return_val[1] + 1] != 0)
							{
								who_will_play = 0;
								board[row][column + return_val[1] + 1] = 2;
								player2[j].setTexture(player2_texture);
								player2[j].setPosition(sf::Vector2f(325, 365));
								player2[j].move(sf::Vector2f((column + return_val[1] + 1) * 57.5, 70 * (row + 1)));
								j++;
								move2++;
								player1[j].setTexture(player1_texture);
								player1[j].setPosition(sf::Vector2f(325, 365));
								column = 0; row = 0;
								cout << "right  \n";

							}
						}
						else if (is_valled(row, column + return_val[0]) == true)
						{
							return_val[0]--;
							if (board[row][column - return_val[0] - 1] == 0 && board[row + 1][column - return_val[0] - 1] != 0)
							{
								who_will_play = 0;
								board[row][column - return_val[0] - 1] = 2;
								player2[j].setTexture(player2_texture);
								player2[j].setPosition(sf::Vector2f(325, 365));
								player2[j].move(sf::Vector2f((column - return_val[0] - 1) * 57.5, 70 * (row + 1)));
								j++;
								move2++;
								player1[j].setTexture(player1_texture);
								player1[j].setPosition(sf::Vector2f(325, 365));
								column = 0; row = 0;
								cout << "left \n";

							}
						}
					}
				}
				while (who_will_play == 1 && playy == 0)
				{
					row = 0;
					column = 0;
					int random_column = rand() % 8;
					player2[j].setTexture(player2_texture);
					player2[j].setPosition(sf::Vector2f(325, 365));

					for (int first_empty_row_from_below = 7; first_empty_row_from_below > 0; first_empty_row_from_below--)
					{
						if (board[first_empty_row_from_below][random_column] == 0)
						{
							board[first_empty_row_from_below][random_column] = 2;
							who_will_play = 0;
							player2[j].move(sf::Vector2f(random_column * 57.5, 70 * (first_empty_row_from_below + 1)));
							move2++;
							if (check_ddown(first_empty_row_from_below, random_column, 2) == 4 || check_right_diagonal(first_empty_row_from_below, random_column, 2)[0] + check_right_diagonal(first_empty_row_from_below, random_column, 2)[1] == 4 || check_left_diagonal(first_empty_row_from_below, random_column, 2)[0] + check_left_diagonal(first_empty_row_from_below, random_column, 2)[1] == 4 || check_Right_Left(first_empty_row_from_below, random_column, 2)[0] + check_Right_Left(first_empty_row_from_below, random_column, 2)[1] == 4)
							{
								playy = 1;
								j++;
								window_winner2.create(VideoMode(300, 600), "winner");
								music_play.stop();
								winning.play();

							}

							cout << first_empty_row_from_below << " " << random_column << endl;
							if (playy == 0)
							{
								cout << "random \n";
								j++;
								player1[j].setTexture(player1_texture);
								player1[j].setPosition(sf::Vector2f(325, 365));
							}
							break;
						}
					}
				}


				}
			}
			if (playy == 0 && j >= 32) {
				window_tie.create(VideoMode(300, 600), "Tie Case");
				window.close();
				window_medium.close();
				window_multi.close();
				music_play.stop();
				winning.play();
				games++;
				playy = 1;
			}
		}
		window_medium.display();
		window_medium.clear();
		window_medium.draw(background_board1);
		for (int i = 0; i <= j && i <= 31; i++)
		{
			window_medium.draw(player1[i]);
			window_medium.draw(player2[i]);
		}
		//////////////////////////////////////////////////////////////Hard lavel/////////////////////////////////////////////////////////////////////


		while (window_hard.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window_hard.close();
				break;
				if (playy == 0)
				{
					///////////////////////////////////////////////////////user turn////////////////////////////////////////////////////////
			case sf::Event::KeyPressed:
				switch (evnt.key.code)
				{
				case sf::Keyboard::Right:
					if (column + 1 <= 7)
					{
						column++;
						player1[j].move(sf::Vector2f(57.5, 0));
					}
					break;
				case sf::Keyboard::Left:
					if (column - 1 >= 0)
					{
						column--;
						player1[j].move(sf::Vector2f(-57.5, 0));
					}
					break;
				case sf::Keyboard::Enter:
					if (who_will_play == 0)
					{
						for (int first_empty_row_from_below = 7; first_empty_row_from_below >= 0; first_empty_row_from_below--)
						{
							if (board[first_empty_row_from_below][column] == 0)
							{
								who_will_play = 1;
								board[first_empty_row_from_below][column] = 1;
								row = first_empty_row_from_below;
								player1[j].move(sf::Vector2f(0, (first_empty_row_from_below + 1) * 70));
								coin_hit.play();
								move1++;
								if (check_ddown(first_empty_row_from_below, column, 1) == 4 || check_right_diagonal(first_empty_row_from_below, column, 1)[0] + check_right_diagonal(first_empty_row_from_below, column, 1)[1] == 4 || check_left_diagonal(first_empty_row_from_below, column, 1)[0] + check_left_diagonal(first_empty_row_from_below, column, 1)[1] == 4 || check_Right_Left(first_empty_row_from_below, column, 1)[0] + check_Right_Left(first_empty_row_from_below, column, 1)[1] == 4)
								{
									playy = 1;
									j++;
									window_winner.create(VideoMode(300, 600), "winner");
									music_play.stop();
									winning.play();
								}
								break;
							}
						}
					}
					for (int i = 0; i <= 7; i++)
					{
						for (int jj = 0; jj <= 7; jj++)
						{
							cout << board[i][jj] << "   ";
						}
						cout << endl;
					}
					break;
				}
				////////////////////////////////////////////////////////// HARD HORIZONTAL CHECK  ////////////////////////////////////////
				while (who_will_play == 1 && playy == 0)
				{
					if (who_will_play == 1)
					{
						vector<int>hori = horizontal(2);
						cout << hori[0] << "  " << hori[1] << endl;
						if (hori[0] != -1 && board[hori[0]][hori[1] + 3] == 0 && (hori[0] == 7 || board[hori[0] + 1][hori[1] + 3] != 0))
						{
							board[hori[0]][hori[1] + 3] = 2;
							player2[j].setTexture(player2_texture);
							player2[j].setPosition(sf::Vector2f(325, 365));
							player2[j].move(sf::Vector2f((hori[1] + 3) * 57.5, 70 * (hori[0] + 1)));
							move2++;
							j++;
							who_will_play = 0;
							column = 0;
							if (check_ddown(hori[0], hori[1], 2) == 4 || check_right_diagonal(hori[0], hori[1], 2)[0] + check_right_diagonal(hori[0], hori[1], 2)[1] == 4 || check_left_diagonal(hori[0], hori[1], 2)[0] + check_left_diagonal(hori[0], hori[1], 2)[1] == 4 || check_Right_Left(hori[0] + 3, hori[1], 2)[0] + check_Right_Left(hori[0], hori[1], 2)[1] == 4)
							{
								playy = 1;
								j++;
								window_winner2.create(VideoMode(300, 600), "winner");
								music_play.stop();
								winning.play();
								break;
							}
							player1[j].setTexture(player1_texture);
							player1[j].setPosition(sf::Vector2f(325, 365));
						}
					}
					/////////////
					if (who_will_play == 1)
					{
						vector<int>hori = horizontal(1);
						cout << hori[0] << " " << hori[1] << endl;
						if (who_will_play == 1 &&
							hori[0] != -1 && board[hori[0]][hori[1] + 3] == 0 && board[hori[0] + 1][hori[1] + 3] != 0)
						{
							board[hori[0]][hori[1] + 3] = 2;
							player2[j].setTexture(player2_texture);
							player2[j].setPosition(sf::Vector2f(325, 365));
							player2[j].move(sf::Vector2f((hori[1] + 3) * 57.5, 70 * (hori[0] + 1)));
							move2++;
							j++;
							who_will_play = 0;
							column = 0;
							if (check_ddown(hori[0], hori[1], 2) == 4 || check_right_diagonal(hori[0], hori[1], 2)[0] + check_right_diagonal(hori[0], hori[1], 2)[1] == 4 || check_left_diagonal(hori[0], hori[1], 2)[0] + check_left_diagonal(hori[0], hori[1], 2)[1] == 4 || check_Right_Left(hori[0], hori[1], 2)[0] + check_Right_Left(hori[0], hori[1], 2)[1] == 4)
							{
								playy = 1;
								j++;
								window_winner2.create(VideoMode(300, 600), "winner");
								music_play.stop();
								winning.play();
								break;
							}
							player1[j].setTexture(player1_texture);
							player1[j].setPosition(sf::Vector2f(325, 365));
						}
					}
					/////////////////////////////////////HARD VERTICAL CHECK/////////////////////////////////////////////////
					if (who_will_play == 1)
					{
						vector<int>hori = vertical(2);
						if (hori[0] != -1 && board[hori[0] - 3][hori[1]] == 0)
						{
							cout << hori[0] << "  " << hori[1] << endl;
							board[hori[0] - 3][hori[1]] = 2;
							player2[j].setTexture(player2_texture);
							player2[j].setPosition(sf::Vector2f(325, 365));
							player2[j].move(sf::Vector2f((hori[1]) * 57.5, 70 * (hori[0] - 2)));
							move2++;
							j++;
							who_will_play = 0;
							column = 0;
							if (check_ddown(hori[0] - 3, hori[1], 2) == 4 || check_right_diagonal(hori[0], hori[1], 2)[0] + check_right_diagonal(hori[0], hori[1], 2)[1] == 4 || check_left_diagonal(hori[0], hori[1], 2)[0] + check_left_diagonal(hori[0], hori[1], 2)[1] == 4 || check_Right_Left(hori[0], hori[1], 2)[0] + check_Right_Left(hori[0], hori[1], 2)[1] == 4)
							{
								playy = 1;
								j++;
								window_winner2.create(VideoMode(300, 600), "winner");
								music_play.stop();
								winning.play();
								break;
							}
							player1[j].setTexture(player1_texture);
							player1[j].setPosition(sf::Vector2f(325, 365));
						}
					}///////////////////////
					if (who_will_play == 1)
					{
						vector<int>hori = vertical(1);
						{
							if (hori[0] != -1 && board[hori[0] - 3][hori[1]] == 0)
							{
								cout << hori[0] << "  " << hori[1] << endl;
								board[hori[0] - 3][hori[1]] = 2;
								player2[j].setTexture(player2_texture);
								player2[j].setPosition(sf::Vector2f(325, 365));
								player2[j].move(sf::Vector2f((hori[1]) * 57.5, 70 * (hori[0] - 2)));
								move2++;
								j++;
								who_will_play = 0;
								column = 0;
								if (check_ddown(hori[0] + 3, hori[1], 2) == 4 || check_right_diagonal(hori[0], hori[1], 2)[0] + check_right_diagonal(hori[0], hori[1], 2)[1] == 4 || check_left_diagonal(hori[0], hori[1], 2)[0] + check_left_diagonal(hori[0], hori[1], 2)[1] == 4 || check_Right_Left(hori[0], hori[1], 2)[0] + check_Right_Left(hori[0], hori[1], 2)[1] == 4)
								{
									playy = 1;
									j++;
									window_winner2.create(VideoMode(300, 600), "winner");
									music_play.stop();
									winning.play();
									break;
								}
								player1[j].setTexture(player1_texture);
								player1[j].setPosition(sf::Vector2f(325, 365));
							}
						}
					}
					while (who_will_play == 1)
					{

						row = 0;
						column = 0;
						int random_column = rand() % 8;
						player2[j].setTexture(player2_texture);
						player2[j].setPosition(sf::Vector2f(325, 365));

						for (int first_empty_row_from_below = 7; first_empty_row_from_below > 0; first_empty_row_from_below--)
						{
							if (board[first_empty_row_from_below][random_column] == 0)
							{
								board[first_empty_row_from_below][random_column] = 2;
								who_will_play = 0;
								player2[j].move(sf::Vector2f(random_column * 57.5, 70 * (first_empty_row_from_below + 1)));
								move2++;
								if (check_ddown(first_empty_row_from_below, random_column, 2) == 4 || check_right_diagonal(first_empty_row_from_below, random_column, 2)[0] + check_right_diagonal(first_empty_row_from_below, random_column, 2)[1] == 4 || check_left_diagonal(first_empty_row_from_below, random_column, 2)[0] + check_left_diagonal(first_empty_row_from_below, random_column, 2)[1] == 4 || check_Right_Left(first_empty_row_from_below, random_column, 2)[0] + check_Right_Left(first_empty_row_from_below, random_column, 2)[1] == 4)
								{
									playy = 1;
									j++;
									window_winner2.create(VideoMode(300, 600), "winner");
									music_play.stop();
									winning.play();
									break;
								}
								cout << first_empty_row_from_below << " " << random_column << endl;
								if (playy == 0)
								{
									cout << "random \n";
									j++;
									player1[j].setTexture(player1_texture);
									player1[j].setPosition(sf::Vector2f(325, 365));
								}
								break;
							}
						}
					}
				}
				//////////////////////////////////////////////////////////////////////////////////////////draw**////////////////////////////////////////////////////////////////////////////////////////
				break;
				}
			}
			if (playy == 0 && j >= 32) {
				window_tie.create(VideoMode(300, 600), "Tie Case");
				music_play.stop();
				winning.play();
				games++;
				playy = 1;
			}
		}
		window_hard.clear();
		window_hard.draw(background_board1);
		for (int i = 0; i <= j && i <= 31; i++)
		{
			window_hard.draw(player1[i]);
			window_hard.draw(player2[i]);
		}
		window_hard.display();



		//////////////////////////////////////////////////////////////multiplayer////////////////////////////////////////////////////////////////////
		Event event;

		while (window_multi.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window_multi.close();
				break;
				if (playy == 0)
				{
			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Right:
					if (x + 1 <= 7 && playy == 0)
					{
						if (!who_will_play)
						{
							x++; sprite2[j].move(Vector2f(57.5, 0));
						}
						else
						{
							x++; sprite3[j].move(Vector2f(57.5, 0));
						}
					}
					break;
				case Keyboard::Left:
					if (x - 1 >= 0 && playy == 0)
					{
						if (!who_will_play)
						{
							x--; sprite2[j].move(Vector2f(-57.5, 0));
						}
						else
						{
							x--; sprite3[j].move(Vector2f(-57.5, 0));
						}
					}
					break;
				case Keyboard::Enter:
					if (who_will_play == 0 && playy == 0)                 //Player (1)
					{
						for (int ii = 7; ii >= 0; ii--)
						{
							if (board[ii][x] == 0)
							{
								board[ii][x] = 1;
								sprite2[j].move(Vector2f(0, (ii + 1) * 70));
								move1++;
								coin_hit.play();
								who_will_play = 1;
								x = 0;
								int  count;
								for (int i = 0; i < 8; i++)
								{
									for (int jj = 0; jj < 8; jj++)
									{

										//checks horizontal win
										if (board[i][jj] != 0 && board[i][jj] == board[i][jj + 1] && board[i][jj] == board[i][jj + 2] && board[i][jj] == board[i][jj + 3])
										{
											cout << "\t\tPlayer ( ONE ) Won\n";
											playy = 1;
											j++;
											window_winner.create(VideoMode(300, 600), "winner");
											music_play.stop();
											winning.play();
											games++;
											player = 0;

										}
										//checks vertical win
										if (board[i][jj] != 0 && board[i][jj] == board[i + 1][jj] && board[i][jj] == board[i + 2][jj] && board[i][jj] == board[i + 3][jj])
										{
											cout << "\t\tPlayer ( ONE ) Won\n";
											playy = 1;
											j++;
											window_winner.create(VideoMode(300, 600), "winner");
											music_play.stop();
											winning.play();
											games++;
											player = 0;

										}
										//checks diagonal win
										count = 0;
										for (int k = 1; k < 4; k++)
										{
											if (board[i][jj] == board[i + k][jj + k] && board[i][jj] != 0)
												count++;
											else
												count = 0;
											if (count == 3)
											{
												cout << "\t\tPlayer ( ONE ) Won\n";
												playy = 1;
												j++;
												window_winner.create(VideoMode(300, 600), "winner");
												music_play.stop();
												winning.play();
												games++;
												player = 0;

											}
										}
										count = 0;
										for (int k = 1; k < 4; k++)
										{
											if (board[i][jj] == board[i + k][jj - k] && board[i][jj] != 0)
												count++;
											else
												count = 0;
											if (count == 3)
											{
												cout << "\t\tPlayer ( ONE ) Won\n";
												playy = 1;
												j++;
												window_winner.create(VideoMode(300, 600), "winner");
												music_play.stop();
												winning.play();
												games++;
												player = 0;

											}
										}


									}

								}
								break;
							}
						}
						if (playy == 0) {
							sprite3[j].setTexture(texture3);
							sprite3[j].setPosition(Vector2f(325, 365));
						}
					}
					//
					else if (who_will_play == 1 && playy == 0)                 //Player (2)
					{
						cout << 123;
						for (int ii = 7; ii >= 0; ii--)
						{
							if (board[ii][x] == 0)
							{
								board[ii][x] = 2;
								sprite3[j].move(Vector2f(0, (ii + 1) * 70));
								move2++;
								coin_hit.play();
								who_will_play = 0;
								x = 0;
								int count;
								for (int i = 0; i < 8; i++)
								{
									for (int jj = 0; jj < 8; jj++)
									{
										//checks horizontal win
										if (board[i][jj] != 0 && board[i][jj] == board[i][jj + 1] && board[i][jj] == board[i][jj + 2] && board[i][jj] == board[i][jj + 3])
										{
											cout << "\t\tPlayer ( TWO ) Won\n";
											playy = 1;
											j++;
											window_winner2.create(VideoMode(300, 600), "winner");
											music_play.stop();
											winning.play();
											games++;
											player = 1;

										}
										//checks vertical win
										if (board[i][jj] != 0 && board[i][jj] == board[i + 1][jj] && board[i][jj] == board[i + 2][jj] && board[i][jj] == board[i + 3][jj])
										{
											cout << "\t\tPlayer ( TWO ) Won\n";
											playy = 1;
											j++;
											window_winner2.create(VideoMode(300, 600), "winner");
											music_play.stop();
											winning.play();
											games++;
											player = 1;

										}
										//checks diagonal win
										count = 0;
										for (int k = 1; k < 4; k++)
										{
											if (board[i][jj] == board[i + k][jj + k] && board[i][jj] != 0)
												count++;
											else
												count = 0;
											if (count == 3)
											{
												cout << "\t\tPlayer ( TWO ) Won\n";
												playy = 1;
												j++;
												window_winner2.create(VideoMode(300, 600), "winner");
												music_play.stop();
												winning.play();
												games++;
												player = 1;

											}

										}
										count = 0;
										for (int k = 1; k < 4; k++)
										{
											if (board[i][jj] == board[i + k][jj - k] && board[i][jj] != 0)
												count++;
											else
												count = 0;
											if (count == 3)
											{
												cout << "\t\tPlayer ( Two ) Won\n";
												playy = 1;
												j++;

												window_winner2.create(VideoMode(300, 600), "winner");
												music_play.stop();
												winning.play();
												games++;
												player = 1;

											}

										}
									}
								}
								break;
							}
						}
						if (playy == 0) {
							j++;
							sprite2[j].setTexture(texture2);
							sprite2[j].setPosition(Vector2f(325, 365));
						}
					}
					break;
				}
				break;
				}

			}
			if (playy == 0 && j >= 32) {
				window_tie.create(VideoMode(300, 600), "Tie Case");
				music_play.stop();
				winning.play();
				games++;
				playy = 1;
				player = 2;
			}
		}

		string str = to_string(move1);
		move1text.setString(str);
		//counting move 2
		string str2 = to_string(move2);
		move2text.setString(str2);

		window_multi.clear();
		window_multi.draw(sprite1);

		for (int i = 0; i <= j && i <= 31; i++)
		{
			window_multi.draw(sprite2[i]);
			window_multi.draw(sprite3[i]);
		}
		window_multi.display();

	}


	outgame << games;
	outgame.close();
	ofstream outleaderboard;
	outleaderboard.open("leaderboard.txt", ios::app);
	ifstream innumbers;
	innumbers.open("numbers.txt");
	innumbers >> numbers;
	innumbers.close();
	if (player == 0) {
		outleaderboard << "game " << numbers + 1 << "\t" << "player 1 " << endl;
		numbers += 1;
	}
	if (player == 1) {
		outleaderboard << "game " << numbers + 1 << "\t" << "player 2 " << endl;
		numbers += 1;
	}
	if (player == 2) {
		outleaderboard << "game " << numbers + 1 << "\t" << "Tie " << endl;
		numbers += 1;
	}
	ofstream outnumbers;
	outnumbers.open("numbers.txt");
	outnumbers << numbers;
	outnumbers.close();
	outleaderboard.close();
	char l;
	ifstream inleaderboard;
	inleaderboard.open("leaderboard.txt");
	while (!inleaderboard.eof()) {
		inleaderboard.get(l);
		cout << l;
	}
	inleaderboard.close();

	return 0;
}
