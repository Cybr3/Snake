#include <chrono>
#include <thread>

#include "map.h"


int main() {
	
	bool game = true;

	Map screen;
	screen.initialize();

	while (game == true) {
		

		screen.set_map();
		screen.get_map();


		std::this_thread::sleep_for(200ms);
		system("CLS");
	}

}

