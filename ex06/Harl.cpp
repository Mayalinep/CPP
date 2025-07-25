#include "Harl.hpp"
#include "Display.hpp"

//constructor
Harl::Harl(){
	std::cout << std::endl;
	typewriter_effect("Harl start to complain...");
	std::cout << std::endl;
	std::cout << std::endl;
	usleep(400000);
}

//debug
void Harl::debug(void){
	std::cout << COLOR_DEBUG << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << COLOR_RESET << std::endl;
	usleep(900000);
}
//info
void Harl::info(void){
	std::cout << COLOR_INFO << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << COLOR_RESET << std::endl;
	usleep(900000);
}	
//warning
void Harl::warning(void){
	std::cout << COLOR_WARNING << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n" << COLOR_RESET << std::endl;
	usleep(900000);
}
void Harl::error(void){
	std::cout << COLOR_ERROR << "This is unacceptable! I want to speak to the manager now." << COLOR_RESET << std::endl;
	usleep(500000);
}

//fonction to complain
void Harl::complain(std::string level){
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complain[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	int index = -1; //index at -1 because if the level is not found => print default message
	for( int i = 0; i < 4; i++){
		if(levels[i] == level){
			index = i;
			break;
		}
	}
	switch(index){
		case 0 :
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*complain[0])();
		case 1 : 
			std::cout << "[ INFO ]" << std::endl;
			(this->*complain[1])();
		case 2 : 
			std::cout << "[ WARNING ]" << std::endl;
			(this->*complain[2])();
		case 3 :
			std::cout << "[ ERROR ]" << std::endl;
			(this->*complain[3])();
			break;
		default:
			typewriter_effect("[ Probably complaining about insignificant problems ]");
			break;
	}
}

Harl::~Harl(){
	typewriter_effect("Harl stop to complain...");
	std::cout << std::endl;
}