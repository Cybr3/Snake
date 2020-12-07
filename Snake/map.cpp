#include "map.h"

Map::Map(){
	width = 31;
	height = 21;
	border = char(221);
	map[31][21];
	Snake snake;
}

Map::~Map() {}

void Map::set_map() {
	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			map[x][y] = ' ';

			if (x == && y ==)
			
			if (y == 0 || x == 0 || y == height - 1 || x == width - 1) { map[x][y] = border; }
		}
	}
}

char Map::get_map() {
	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			cout << map[x][y];
		}
		cout << endl;
	}
}

