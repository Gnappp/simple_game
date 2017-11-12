#include "SnakeModule.h"

Logic::Logic(){}

void Logic::Game(){
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
}