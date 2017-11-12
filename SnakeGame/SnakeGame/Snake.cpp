#include"SnakeModule.h"


Snake::Snake(){

	length = 0;
	head_x = 0;
	head_y = 0;
	head_position = { head_x, head_y };

	new_body.push_back(head_position);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), new_body[0]);
	cout << "бс";
	feed.create_feed(new_body);
}
void Snake::down_head(){
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
void Snake::up_head(){
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
void Snake::left_head(){
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
void Snake::right_head(){
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
void Snake::print_snake(){
	for (int i = 0; i < old_body.size(); i++){
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old_body[i]);
		cout << " ";
	}
	for (int i = 0; i < new_body.size(); i++){
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), new_body[i]);
		cout << "бс";
	}
}
void Snake::feeding()
{
	if (feed.get_feed().X == head_position.X && feed.get_feed().Y == head_position.Y)
	{
		length += 1;
		feed.create_feed(new_body);
	}
}