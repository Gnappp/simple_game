#include"SnakeModule.h"

Range::Range(){
	min_x = 0;
	min_y = 0;
	max_x = 40;
	max_y = 20;
}

int Range::get_min_y(){ return min_y; }
int Range::get_min_x(){ return min_x; }
int Range::get_max_y(){ return max_y; }
int Range::get_max_x(){ return max_x; }
