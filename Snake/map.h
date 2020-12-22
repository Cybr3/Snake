#pragma once
#include "snake.h"
#include "food.h"

using namespace std;

class Map {
public:
	Map();
	~Map();

	void set_map(Snake*, food*);
	void get_map();

private:
	unsigned short height;
	unsigned short width;
	char border;

	char map[32][22];
	char old_map[32][22];

	bool first_run;
};
