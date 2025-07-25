#include "Zombie.hpp"
#include "display.hpp"

int main()
{
	//Script
	std::cout << std::endl;
	typingEffect("***** You look at the horizon, and see a horde of zombies approaching... *****\n", 10000);
	usleep(1000);
	typingEffect("You see a zombie named Bob...\n", 10000);
	usleep(1000);
	typingEffect("You take your weapon and prepare to fight...\n", 10000);


	//Create a zombie on the stack
	randomChump("Bob");

	//Script
	std::cout << std::endl;
	typingEffect("You see a another zombie named Audrey...\n", 10000);
	usleep(1000);

	//Create a zombie on the heap
   	Zombie* zombie = newZombie("Audrey");
    zombie->announce(); 
	delete zombie;
	std::cout << std::endl;
    return (0);
}