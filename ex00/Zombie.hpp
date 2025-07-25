#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <unistd.h>
#include <string>
#include <iostream>
#include "display.hpp"

// color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class Zombie{
    private:
        std::string name;


    public:
	//constructor
    Zombie(std::string name);
	//method
    void announce();
	//destructor
    ~Zombie();
};
//function
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif