#include "Display.hpp"


void clignotant_effect(std::string text){
	for(int i = 0; i < 5; i++){
		std::cout << GREY_COLOR << text << COLOR_RESET << std::endl;
		usleep(400000);
		std::cout << "                   \r" << std::flush;
		usleep(400000);
	}
}

void typewriter_effect(const std::string& text, useconds_t delay) {
    for (size_t i = 0; i < text.length(); ++i) {
        std::cout << text[i] << std::flush;
        usleep(delay);
    }
    std::cout << std::endl;
}

void printProgressBar(int percent){
	int totalBlocks = 20;
	int progressCount = percent * totalBlocks / 100;
	std::cout << " \r[";
	for(int i = 0; i < totalBlocks; i++){
		if(i < progressCount)
			std::cout << "■";
		else
			std::cout << "□";
	}
	std::cout << "] " << percent << "%" << std::flush;
}
