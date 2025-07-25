#include "Weapon.hpp"


Weapon::Weapon(std::string type) : type(type){
	std::cout << std::endl;
	std::cout << NIGHT_BLUE << " * A magical " << RESET << type << NIGHT_BLUE << " appeared in the inventory *" << RESET << std::endl;
	std::cout << std::endl;
}

Weapon::Weapon(){
	
}

const std::string& Weapon::getType(){
	return (this->type);
}

void Weapon::setType(std::string type){
	std::cout << std::endl;
	std::cout << MOON_CYAN << " WIIINX !! The Power of the fairies !" << RESET << std::endl;
	std::cout << MOON_CYAN << " * The magical " << RESET << this->type << MOON_CYAN << " is now a " << RESET << type << NIGHT_BLUE << " *" << RESET << std::endl;
	std::cout << std::endl;
	this->type = type;
}

Weapon::~Weapon(){
	
}