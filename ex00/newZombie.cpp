#include "Zombie.hpp"

// Create a zombie on the heap and return it
Zombie* newZombie(std::string name){
    Zombie* zombie = new Zombie(name);
    return (zombie);
}

