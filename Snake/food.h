#pragma once
#include <random>

class food {
public:
	food();
	~food();

	void initialize();

	void set_active();
	bool get_active();

	void get_food(unsigned short*, unsigned short*);
	char get_food_figure();



private:
	bool active;

	char figure;

	unsigned short food_pos_x;
	unsigned short food_pos_y;


};

