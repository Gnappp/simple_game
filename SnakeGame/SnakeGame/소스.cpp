//클래스를 분할관리 하는 습관을 기르자.
#include"SnakeModule.h"

//메인 메뉴에 로직을 박지 말자.
int main(){
	Logic logic;
	while (1)
	{
		logic.Game();
		Sleep(150);
	}
}