#include "Zombie.hpp"

//constructor
Zombie::Zombie(std::string name) : name(name) {
	
}

//method
void Zombie::announce()
{
 std::cout << name <<" : BraiiiiiiinnnzzzZ..."<< std::endl;
}
//destructor
Zombie::~Zombie(){
    std::cout << name << " has been defeated... But the war continues..." << std::endl;
}
