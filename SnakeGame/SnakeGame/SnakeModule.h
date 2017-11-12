#ifndef SNAKE_MODULE
#define SNAKE_MODULE

#include<iostream>
#include<windows.h>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<process.h>

using namespace std;

class Range{
private:
	int min_x, min_y, max_x, max_y;
public:
	Range();

	int get_min_y();
	int get_min_x();
	int get_max_y();
	int get_max_x();
};

class Stadium{
private:
	Range range;
public:
	Stadium();
	void init();
};

class Feed{
private:
	COORD feed;
public:
	Feed();
	void create_feed(vector<COORD> body);
	COORD get_feed();
};

class GameOver{
private:
	Range range;
public:
	GameOver();
	void check(vector<COORD> body);
};

class Snake{
private:
	int length;
	int head_x, head_y;
	vector<COORD> new_body;
	vector<COORD> old_body;
	COORD head_position;
	Feed feed;
	GameOver go;
public:
	Snake();
	void down_head();
	void up_head();
	void left_head();
	void right_head();
	void print_snake();
	void feeding();
};

class Logic{
private:
	Stadium stadium;
	Range range;
	Snake snake;
	int state = VK_RIGHT;
public:
	Logic();
	void Game();
};

#endif // !SNAKE_MODULE
