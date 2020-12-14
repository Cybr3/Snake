#include <chrono>
#include <thread>

#include "map.h"

#include "game_logic.h"


int main() {
	Map frame;
	Snake snake;
	food snack;

	snake.initialize();
	bool menu = true;
	srand(time(NULL));

	while (menu) {


		while (game) {
			snake.set_head();
			snake.set_tail();

			frame.set_map(snake);
			frame.get_map(snake);

			logic();

			std::this_thread::sleep_for(200ms);
		}
	}
	return 0;
}

