#include "Zombie.hpp"
#include "display.hpp"

// Constructeur par défaut
Zombie::Zombie() {
    this->name = "";
}

// Constructeur avec nom
Zombie::Zombie(std::string name) {
    this->name = name;
}

// Setter pour le nom
void Zombie::setName(std::string name) {
    this->name = name;
}

// Announce avec le nom
void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ......" << std::endl;
}

// Destructeur avec nom
Zombie::~Zombie() {
	std::cout << "   \\ | /"<< std::endl;
	std::cout << " '-.;;;.-'" << std::endl;
	std::cout << " -==;;;==-" << std::endl;
	std::cout << " .-';;;'-. " << std::endl;
	std::cout << "   / | \\ " << std::endl;
    std::cout << this->name << " has been defeated!" << std::endl;
	usleep(500000);
}