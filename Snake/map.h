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
	const unsigned int height;
	const unsigned int width;
	char border;

	char map[31][21];
};
