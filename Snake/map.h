#pragma once
#include "snake.h"

using namespace std;

class Map {
public:
	Map();
	~Map();
	void set_map();
	char get_map();
	
private:
	unsigned int height;
	unsigned int width;
	char border;

	char map[31][21];

	Snake snake;
};
