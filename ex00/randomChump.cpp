#include "Zombie.hpp"

// Create a zombie on the stack and announce it
void randomChump(std::string name){
    Zombie zombie(name);
    zombie.announce();
    return;
}
