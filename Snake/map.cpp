#include "map.h"
#include "cursor.h"

#include <windows.h>
#include <ConsoleApi2.h>


Map::Map() {
	width = 31;
	height = 21;
	border = '#';
	map[31][21] = {};
	old_map[31][21] = {};
	Snake snake;

	first_run = true;
}

Map::~Map() {}

//generates the map which will be processed further on in get_map
void Map::set_map(Snake *snake, food *snack) {
	unsigned short a;
	unsigned short b;	
	unsigned short pos_bufferx;
	unsigned short pos_buffery;

	for (unsigned short y = 0; y < height; y++) {
		for (unsigned short x = 0; x < width; x++) {
			map[x][y] = char(219);

			for (int l = 0; l < snake->get_length(); l++) {
				a = 0;
				b = 0;
				snake->get_tail(&a, &b, l);
				if (x == a && y == b) { map[x][y] = snake->get_tail_figure(); }
			}

			snack->get_food(&a, &b);
			if (x == a && y == b) { map[x][y] = snack->get_figure(); }

			snake->get_head(&a, &b);
			if (x == a && y == b) { map[x][y] = snake->get_head_figure(); }

			if (y == 0 || x == 0 || y == height - 1 || x == width - 1) { map[x][y] = border; }
		}
	}
}

//prints the map in colors
void Map::get_map() {
	char map_buffer;

	ShowConsoleCursor(false);

	if (first_run) {
		for (unsigned short y = 0; y < height; y++) {
			for (unsigned short x = 0; x < width; x++) {
				map_buffer = map[x][y];

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);

				if (map_buffer == '#') { 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136); 
					map_buffer = char(219);
				}
				else if (map_buffer == '+') { 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 114);
					map_buffer = char(254);
				}
				else if (map_buffer == 'o') { 
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116); 
					map_buffer = char(254);
				}

				setCursorPosition(x, y);
				cout << map_buffer;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);


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
		ShowConsoleCursor(false);
		for (unsigned short y = 0; y < height; y++) {
			for (unsigned short x = 0; x < width; x++) {
				if (map[x][y] != old_map[x][y]) {
					map_buffer = map[x][y];

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);

					if (map_buffer == '#') {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);
						map_buffer = char(219);
					}
					else if (map_buffer == '+') {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 114);
						map_buffer = char(254);
					}
					else if (map_buffer == 'o') {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
						map_buffer = char(254);
					}

					setCursorPosition(x, y);
					cout << map_buffer;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				}
			}
		}
		for (unsigned short y = 0; y < height; y++) {
			for (unsigned short x = 0; x < width; x++) {
				old_map[x][y] = map[x][y];
			}
		}
	}
}