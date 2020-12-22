#include <iostream>
#include "snake.h"
#include "map.h"
#include "food.h"

using namespace std;

void logic(Snake *object_snake, Map *object_map, food *object_food, bool *game, unsigned int *points) {
	unsigned short head_x = 0;
	unsigned short head_y = 0;

	unsigned short c = 0;
	unsigned short d = 0;

	object_snake->get_head(&head_x, &head_y);
	object_food->get_food(&c, &d);

	if (head_x == c && head_y == d) {
		object_food->set_active();
		object_snake->set_length();
		*points += 10;
	}

	if (head_y == 0 || head_x == 0 || head_y == 20 || head_x == 30) {
		*game = false;
	}

	object_snake->get_head(&a, &b);
	for (unsigned short n = 0; n < object_snake->get_length(); n++) {
		unsigned short tail_x = 0;
		unsigned short tail_y = 0;

		object_snake->get_tail(&tail_x, &tail_y, n);

		if (a == tail_x && b == tail_y) {
			*game = false;
		}
	}

}