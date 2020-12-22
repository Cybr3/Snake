#include <cstdlib>
#include "food.h"


food::food() {
	active = true;
	figure = 'o';

	food_pos_x = 0;
	food_pos_y = 0;
}

food::~food() {}

void food::initialize() {
	active = true;
	food_pos_x = (rand() % 29) + 1;
	food_pos_y = (rand() % 19) + 1;
}

void food::set_active() {
	active = false;
}

void food::get_food(unsigned short* x, unsigned short* y) {
	*x = food_pos_x;
	*y = food_pos_y;
}

char food::get_figure() {
	return figure;
}

bool food::get_active() {
	return active;
}