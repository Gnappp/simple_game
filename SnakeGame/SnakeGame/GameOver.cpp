#include"SnakeModule.h"


GameOver::GameOver(){}

void GameOver::check(vector<COORD> body){
	if (body[0].X > range.get_max_x() - 1 || body[0].X < range.get_min_x()){
		COORD cord = { 26, 10 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
		cout << "GAME OVER";
		exit(0);
	}
	if (body[0].Y > range.get_max_y() - 1 || body[0].Y < range.get_min_y()){
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