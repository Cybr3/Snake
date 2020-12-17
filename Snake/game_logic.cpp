#include <iostream>
#include "snake.h"
#include "map.h"
#include "food.h"

using namespace std;

void logic(Snake *object_snake, Map *object_map, food *object_food, bool *game, unsigned int *points) {
	unsigned short a = 0;
	unsigned short b = 0;

	unsigned short c = 0;
	unsigned short d = 0;

	object_food->get_food(&c, &d);
	object_snake->get_head(&a, &b);

	if (a == c && b == d) {
		object_food->set_active();
		object_snake->set_length();
		*points += 10;
	}

	if (b == 0 || a == 0 || b == 20 || a == 30) {
		*game = false;
		
	}

	for (int n = 0; n < object_snake->get_length(); n++) {
		unsigned short tail_x = n;
		unsigned short tail_y = n;

		object_snake->get_tail(&tail_x, &tail_y);

		if (a == tail_x && b == tail_y) {
			*game = false;
		}
	}

}