/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:57:52 by maya              #+#    #+#             */
/*   Updated: 2025/07/23 15:03:57 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "display.hpp"

int main() {
	//script
    typingEffect("***** The night falls... A horde of zombies rises from the ground! *****\n", 41000);
	typingEffect("You realize... they're not ordinary zombies... they're MINION ZOMBIES!\n", 41000);
	std::cout << std::endl;

	//create a horde of zombies
    int N = 5;
    Zombie* horde = zombieHorde(N, "MINION");
	
	//script
    std::cout << "A horde of " << N << " MINION ZOMBIES appears!\n" << std::endl;
	usleep(100000);
	
	std::cout << std::endl;
    for (int i = 0; i < N; ++i){
        horde[i].announce();
		usleep(200000);
	}
	usleep(100000);
	
	typingEffect("The minion zombies look at you with big, yellow eyes...\n", 41000);
	typingEffect("They start chanting: \"Bananaaaaa! Brainzzzz! Bananaaaa!\"\n", 41000);
	typingEffect("You take your weapon and defend yourself ..!!!\n", 41000);
	std::cout << std::endl;

	usleep(100000);
	
    delete[] horde;
	
    typingEffect("***** The horde has been defeated... For now. *****\n", 40000);
	std::cout << std::endl;
    return 0;
}