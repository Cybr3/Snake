#include "snake.h"

Snake::Snake() {
	snake_pos_x[99];
	snake_pos_y[99];
	length = 0;
}

Snake::~Snake(){}

void Snake::initialize() {
	snake_pos_x[0] = 15;
	snake_pos_y[0] = 15;
}

void Snake::set_head(unsigned int pos_x, unsigned int pos_y) {
	snake_pos_x[0] = pos_x;
	snake_pos_y[0] = pos_y;
}

void Snake::set_tail() {
	
}

void Snake::set_length() {
	length++;
}

unsigned int Snake::get_tail(unsigned int pos) {
	return tail_pos[pos];
}

unsigned int Snake::get_head(){
	return snake_pos_x[0], snake_pos_y[0];

}



unsigned int Snake::get_length(){
	return length;
}