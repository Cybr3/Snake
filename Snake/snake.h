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

	char get_tail_figure();
	char get_head_figure();

private:
	unsigned int snake_pos_x[100];
	unsigned int snake_pos_y[100];

	unsigned int length;

	char head_figure;
	char tail_figure;
};
