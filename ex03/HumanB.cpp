#include "HumanB.hpp"


HumanB::HumanB(std::string name) : name(name), weapon(NULL){
	std::cout << SILVER << name << RESET << NIGHT_BLUE << " has terrified, he has no weapon " << RESET << std::endl;
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
	std::cout << NIGHT_BLUE << " * open his inventory and grab a new weapon *" << RESET << std::endl;
	this->weapon = &weapon;
	std::cout << std::endl;
}

void HumanB::attack(){
	if (this->weapon)
		std::cout << DEEP_VIOLET << this->name << " attacks with their " << this->weapon->getType() << RESET << std::endl;
	else
		std::cout << NIGHT_BLUE << this->name << " has no weapon!" << RESET << std::endl;
}

HumanB::~HumanB(){
	
}