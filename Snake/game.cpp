#include <chrono>
#include <thread>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "map.h"
#include "cursor.h"
#include "game_logic.h"


int main() {
	Map frame;
	Snake snake;
	food snack;

	snack.initialize();
	snake.initialize();

	bool menu = true;
	bool game = false;

	bool first_run = true;
	bool show_once = true;

	srand(time(NULL));

	unsigned int points = 0;

	while (menu) {
		ShowConsoleCursor(false);
		if (first_run && show_once) {
			cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << endl;
			cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << endl;
			cout << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << endl;

			cout << endl << endl << "DO YOU WANT TO PLAY? [Y/N]";
			show_once = false;
		}
		if (_kbhit()){
			char i = _getch();
			switch (i) {
			case 'y':
				game = true;
				menu = true;
				first_run = false;
				system("CLS");
				break;
			case 'n':
				game = false;
				menu = false;
				break;

			}
		}
				

		while (game) {

			if (snack.get_active() == false) {
				snack.initialize();
			}

			snake.set_head();
			snake.set_tail();

			logic(&snake, &frame, &snack, &game, &points);

			frame.set_map(&snake, &snack);
			frame.get_map();

			std::this_thread::sleep_for(200ms);
		}


		if (!game) {
			system("CLS");
			setCursorPosition(0, 0);
			ShowConsoleCursor(true);
			cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << endl;
			cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << ' ' << endl;
			cout << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << endl;
			cout << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << ' ' << ' ' << ' ' << ' ' << char(219) << char(219) << ' ' << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << ' ' << endl;


			cout << "YOUR POINTS: " << points;

			cout << endl << endl << "DO YOU WANT TO PLAY AGAIN? [Y/N]" << endl;

		}
	}

	if (!game && !menu) {
		return 0;
	}
}

