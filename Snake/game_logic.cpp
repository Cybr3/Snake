#include <iostream>
#include "snake.h"
#include "map.h"
#include "food.h"

using namespace std;

void logic(Snake object_snake, Map object_map, food obejct_food) {
	unsigned short a = 0;
	unsigned short b = 0;

	object_snake.get_head(&a, &b);

	if (b == 0 || a == 0 || b == 20 || a == 30) {
		object_snake.~Snake();
	}
	for (int n = 0; n < length; n++) {
		if (snake_head_x == snake_tail_x[n] && snake_head_y == snake_tail_y[n]) {

		}
	}









