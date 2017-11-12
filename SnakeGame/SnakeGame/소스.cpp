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
	Range(){
		min_x = 0;
		min_y = 0;
		max_x = 40;
		max_y = 20;
	}

	int get_min_y(){ return min_y; }
	int get_min_x(){ return min_x; }
	int get_max_y(){ return max_y; }
	int get_max_x(){ return max_x; }

};

class Stadium{
private:
	Range range;
public:
	Stadium(){
		COORD pos;
		for (int i = 0; i < range.get_max_x() + 1; i++){
			if (i % 2 == 0){
				pos = { i, range.get_max_y() };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				cout << "¦¬";
			}
		}//xÃà ¼±±ß±â
		for (int i = 0; i < range.get_max_y() + 1; i++){
			if (range.get_max_y() != i){
				pos = { range.get_max_x(), i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				cout << "¦­";
			}
			if (range.get_max_y() == i){
				pos = { range.get_max_x(), i };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				cout << "¦°";
			}
		}//yÃà ¼±±ß±â
	}
};


class Feed{
private:
	COORD feed;
public:
	Feed(){}
	void create_feed(vector<COORD> body){
		srand(time(NULL));
		int y = rand() % 20;
		int x = rand() % 40;
		if (x % 2 == 1) x -= 1;
		for (int i= 0; i < body.size(); i++){
			if (x == body[i].X && y == body[i].Y){
				int y = rand() % 20;
				int x = rand() % 40;
				if (x % 2 == 1) x -= 1;
				i = 0;
			}
		}
		feed = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), feed);
		cout << "¡Ú";
	}
	
	COORD get_feed(){ return feed; }
};

class GameOver{
private:
	Range range;
public:
	GameOver(){}
	void check(vector<COORD> body){
		if (body[0].X > range.get_max_x()-1 || body[0].X < range.get_min_x()){
			COORD cord = { 26, 10 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
			cout << "GAME OVER";
			exit(0);
		}
		if (body[0].Y > range.get_max_y()-1 || body[0].Y < range.get_min_y()){
			COORD cord = { 26, 10 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
			cout << "GAME OVER";
			exit(0);
		}
		for (int i = 1; i < body.size(); i++){
			if (body[0].X == body[i].X && body[0].Y == body[i].Y){
				COORD cord = { 26, 10 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
				cout << "GAME OVER";
				exit(0);
			}
		}
	}
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
	Snake(){

		length = 0;
		head_x = 0;
		head_y = 0;
		head_position = { head_x, head_y };

		new_body.push_back(head_position);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), new_body[0]);
		cout << "¡á";
		feed.create_feed(new_body);
	}
	void down_head(){
		head_y += 1;
		head_position = { head_x, head_y };
		old_body = new_body;
		new_body.clear();
		new_body.push_back(head_position);
		if (length != 0){
			for (int i = 0; i < length; i++)
			{
				new_body.push_back(old_body[i]);
			}
		}
		print_snake();
		go.check(new_body);
		feeding();
	}
	void up_head(){
		head_y -= 1;
		head_position = { head_x, head_y };

		old_body = new_body;

		new_body.clear();
		new_body.push_back(head_position);
		if (length != 0){
			for (int i = 0; i < length; i++)
			{
				new_body.push_back(old_body[i]);
			}
		}
		print_snake();
		go.check(new_body);
		feeding();
	}
	void left_head(){
		head_x -= 2;
		head_position = { head_x, head_y };
		old_body = new_body;
		new_body.clear();
		new_body.push_back(head_position);
		if (length != 0){
			for (int i = 0; i < length; i++)
			{
				new_body.push_back(old_body[i]);
			}
		}
		print_snake();
		go.check(new_body);
		feeding();
	}
	void right_head(){
		head_x += 2;
		head_position = { head_x, head_y };
		old_body = new_body;
		new_body.clear();
		new_body.push_back(head_position);
		if (length != 0){
			for (int i = 0; i < length; i++)
			{
				new_body.push_back(old_body[i]);
			}
		}
		print_snake();
		go.check(new_body);
		feeding();
	}
	void print_snake(){
		for (int i = 0; i < old_body.size(); i++){
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old_body[i]);
			cout << " ";
		}
		for (int i = 0; i < new_body.size(); i++){
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), new_body[i]);
			cout << "¡á";
		}
	}
	void feeding()
	{
		if (feed.get_feed().X == head_position.X && feed.get_feed().Y == head_position.Y)
		{
			length+=1;
			feed.create_feed(new_body);
		}
	}
};





int main()
{
	Stadium stadium;
	Range range;
	Snake snake;
	int state = VK_RIGHT;
	while (1)
	{
		if (GetKeyState(VK_LEFT) & 0x8000 || state == VK_LEFT) {
			if (state != VK_RIGHT){
				snake.left_head();
				state = VK_LEFT;
			}
		}
	
	
		if (GetKeyState(VK_RIGHT) & 0x8000 || state == VK_RIGHT){
			if (state != VK_LEFT){
				snake.right_head();
				state = VK_RIGHT;
			}
		}
	
	
		if (GetKeyState(VK_UP) & 0x8000 || state == VK_UP){
			if (state != VK_DOWN){
				snake.up_head();
				state = VK_UP;
			}
		}

		if (GetKeyState(VK_DOWN) & 0x8000 || state == VK_DOWN) { 
			if (state != VK_UP){
				snake.down_head();
				state = VK_DOWN;
			}
		}

		Sleep(150);
	}
}