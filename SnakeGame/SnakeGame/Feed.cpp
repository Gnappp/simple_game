#include "SnakeModule.h"

Feed::Feed(){}
void Feed::create_feed(vector<COORD> body){
	srand(time(NULL));
	int y = rand() % 20;
	int x = rand() % 40;
	if (x % 2 == 1) x -= 1;
	for (int i = 0; i < body.size(); i++){
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

COORD Feed::get_feed(){ return feed; }