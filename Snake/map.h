#pragma once
#include "snake.h"

using namespace std;

class Map {
public:
	Map();
	~Map();

	void initialize();

	void set_map();
	void get_map();

	
private:
	unsigned int height;
	unsigned int width;
	char border;

	char map[32][22];

	Snake snake;
};
