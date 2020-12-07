#include "map.h"

Map::Map(){
	width = 31;
	height = 21;
	border = char(219);
	map[31][21] = ' ';
	Snake snake;
}

Map::~Map() {}

void Map::initialize(){
	snake.initialize();
}


void Map::set_map() {
	unsigned int a = 0;
	unsigned int b = 0;

	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			map[x][y] = ' ';

			a, b = snake.get_head();
			if (x == a && y == b) { map[x][y] = snake.get_head_figure(); }
			
			if (y == 0 || x == 0 || y == height - 1 || x == width - 1) { map[x][y] = border; }
		}
	}
}

void Map::get_map() {
	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			cout << map[x][y];
		}
		cout << endl;
	}
}

