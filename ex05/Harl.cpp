

#include "Harl.hpp"


Harl::Harl(){
	std::cout << "Harl start to complain..." << std::endl;
}

void Harl::debug(void){
	std::cout << COLOR_DEBUG << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << COLOR_RESET << std::endl;
}
void Harl::info(void){
	std::cout << COLOR_INFO << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << COLOR_RESET << std::endl;
}
void Harl::warning(void){
	std::cout << COLOR_WARNING << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << COLOR_RESET << std::endl;
}
void Harl::error(void){
	std::cout << COLOR_ERROR << "This is unacceptable! I want to speak to the manager now." << COLOR_RESET << std::endl;
}

void Harl::complain(std::string level){
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complain[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for( int i = 0; i < 4; i++){
		if(levels[i] == level){
			(this->*complain[i])();
			break;
		}
	}
	// switch(index){
	// 	case 0 :
	// 		(this->*complain[0])();
	// 		break;
	// 	case 1 : 
	// 		(this->*complain[1])();
	// 		break;
	// 	case 2 : 
	// 		(this->*complain[2])();
	// 		break;
	// 	case 3 :
	// 		(this->*complain[3])();
	// 		break;
	// 	default:
	// 		std::cout << "Level inconnu" << std::endl;
	// 		break;
	// }
}

Harl::~Harl(){
	std::cout << "Harl stop to complain..." << std::endl;
}
