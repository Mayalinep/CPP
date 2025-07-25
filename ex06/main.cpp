#include "Harl.hpp"
#include "Display.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << " you need to give a level: DEBUG, INFO, WARNING, ERROR" << std::endl;	
        return 1;
    }
	std::cout << std::endl;
    clignotant_effect("Loading...");

	for(int i = 0; i <= 100; i++){
		printProgressBar(i);
		usleep(50000);
	}
	std::cout << std::endl;

    Harl harl;
    harl.complain(argv[1]);
	std::cout << std::endl;
    
    return 0;
}
