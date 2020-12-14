#include <chrono>
#include <thread>
#include <conio.h>
#include "map.h"

#include "game_logic.h"


int main() {
	Map frame;
	Snake snake;
	food snack;

	snake.initialize();
	bool menu = true;
	bool game = false;
	srand(time(NULL));

	while (menu) {

		cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << endl;
		cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
		cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
		cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << endl;
		cout << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
		cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
		cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << endl;

		cout << endl << endl << "DO YOU WANT TO PLAY? [Y/N]";

		if (_kbhit()){
			char i = _getch();
			switch (i) {
			case 'y':
				game = true;
				menu = true;
				system("CLS");
				break;
			case 'n':
				game = false;
				menu = false;
				break;

			}
		}
			

		while (game) {
			snake.set_head();
			snake.set_tail();

			frame.set_map(snake);
			frame.get_map(snake);

			logic(snake, frame, snack, &game);

			std::this_thread::sleep_for(200ms);
		}
		std::this_thread::sleep_for(2s);
		system("CLS");
	}

	if (!game && !menu) {
		return 0;
	}
}

