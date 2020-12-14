#include "map.h"
#include "cursor.h"
#include <windows.h>
#include <ConsoleApi2.h>


Map::Map() {
	width = 31;
	height = 21;
	border = char(219);
	map[31][21] = {};
	old_map[31][21] = {};
	Snake snake;

	first_run = true;
}

Map::~Map() {}

//generates the map which will be processed further on in get_map
void Map::set_map(Snake snake) {
	unsigned short a;
	unsigned short b;

	for (unsigned short y = 0; y < height; y++) {
		for (unsigned short x = 0; x < width; x++) {
			map[x][y] = char(219);

			a = 0;
			b = 0;
			snake.get_head(&a, &b);

			if (x == a && y == b) { map[x][y] = snake.get_head_figure(); }

			if (y == 0 || x == 0 || y == height - 1 || x == width - 1) { map[x][y] = border; }
		}
	}
}

//prints the map in colors
void Map::get_map(Snake snake) {
	unsigned short a;
	unsigned short b;

	ShowConsoleCursor(false);

	if (first_run) {
		for (unsigned short y = 0; y < height; y++) {
			for (unsigned short x = 0; x < width; x++) {
				a = 0;
				b = 0;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);
				if (y == 0 || x == 0 || y == height - 1 || x == width - 1) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); }

				snake.get_head(&a, &b);
				if ((x == a && y == b)) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);
				}
				cout << map[x][y];


			}
			cout << endl;
		}
		first_run = false;
		for (unsigned short y = 0; y < height; y++) {
			for (unsigned short x = 0; x < width; x++) {
				old_map[x][y] = map[x][y];
			}
		}
	}
	else {
		for (unsigned short y = 0; y < height; y++) {
			for (unsigned short x = 0; x < width; x++) {


				if (map[x][y] != old_map[x][y]) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);

					a = 0;
					b = 0;

					snake.get_head(&a, &b);

					if (x == a && y == b) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 130);
					}

					setCursorPosition(x, y);
					cout << map[x][y];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		}
		for (unsigned short y = 0; y < height; y++) {
			for (unsigned short x = 0; x < width; x++) {
				old_map[x][y] = map[x][y];
			}
		}
	}
}