#include <utility>
#include "snake.h"


Snake::Snake() {
	snake_pos_x[99] = 0;
	snake_pos_y[99] = 0;
	length = 0;

	head_figure = char(223);
	tail_figure = char(223);
}

Snake::~Snake(){}

void Snake::initialize() {
	snake_pos_x[0] = 3;
	snake_pos_y[0] = 5;
}

void Snake::set_head(unsigned int pos_x, unsigned int pos_y) {
	snake_pos_x[0] = pos_x;
	snake_pos_y[0] = pos_y;
}

/*generierung der ganzen schlange inklusive des schwanzes mithilfe eines swap algorithmus*/
void Snake::set_tail() {
	unsigned int buffer_x = snake_pos_x[0];
	unsigned int buffer_y = snake_pos_y[0];

	for (unsigned int n = 0; n < length; n++) {
		std::swap(snake_pos_x[n], buffer_x);
		std::swap(snake_pos_y[n], buffer_y);
	}
}

void Snake::set_length() {
	length++;
}

unsigned int Snake::get_tail(unsigned int pos) {
	return snake_pos_x[pos], snake_pos_y[pos];
}

unsigned int Snake::get_head(){
	return snake_pos_x[0], snake_pos_y[0];
}

unsigned int Snake::get_length(){
	return length;
}

char Snake::get_tail_figure() {
	return tail_figure;
}

char Snake::get_head_figure() {
	return head_figure;
}