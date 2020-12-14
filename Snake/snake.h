#pragma once
#include <iostream>
class Snake {
public:
	Snake();
	~Snake();

	void set_head();
	void get_head(unsigned short*, unsigned short*);

	char get_tail_figure();
	char get_head_figure();

	void initialize();

	void last_move_function();

	void set_tail();

private:
	unsigned short snake_head_x;
	unsigned short snake_head_y;

	unsigned short snake_tail_x[1000];
	unsigned short snake_tail_y[1000];

	char head_figure;

	char last_move;

	unsigned short length;
};
