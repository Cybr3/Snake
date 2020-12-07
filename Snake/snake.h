#pragma once
#include <iostream>
class Snake {
public:
	Snake();
	~Snake();

	void set_tail();
	unsigned int get_tail(unsigned int);
	void initialize();

	void set_head(unsigned int, unsigned int);
	unsigned int get_head();

	void set_length();
	unsigned int get_length();

private:
	unsigned int snake_pos_x[100];
	unsigned int snake_pos_y[100];

	int tail_pos[100];

	int length;
};
