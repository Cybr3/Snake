#pragma once
#include <iostream>
class Snake {
public:
	Snake();
	~Snake();

	void set_tail();
	char get_tail();
	void initialize();


	char set_head();
	char get_head();

private:
	char head;
	char tail;
	unsigned int head_pos[2];
	unsigned int tail_pos[100];
};
