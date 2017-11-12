#include "SnakeModule.h"


Stadium::Stadium(){ init(); }

//왠만하면 생성자에 때려박지 말자.
void Stadium::init(){
	COORD pos;
	for (int i = 0; i < range.get_max_x() + 1; i++){
		if (i % 2 == 0){
			pos = { i, range.get_max_y() };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "━";
		}
	}//x축 선긋기
	for (int i = 0; i < range.get_max_y() + 1; i++){
		if (range.get_max_y() != i){
			pos = { range.get_max_x(), i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "┃";
		}
		if (range.get_max_y() == i){
			pos = { range.get_max_x(), i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "┛";
		}
	}//y축 선긋기
}