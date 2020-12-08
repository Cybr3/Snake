#include <chrono>
#include <thread>

#include "map.h"


int main() {
	
	bool game = true;

	Map frame;
	frame.initialize();

	while (game == true) {
		

		frame.set_map();
		frame.get_map();


		std::this_thread::sleep_for(200ms);
		system("CLS");
	}

}

