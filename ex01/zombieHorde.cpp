/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:50:39 by maya              #+#    #+#             */
/*   Updated: 2025/07/22 21:08:39 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombies = new Zombie[N];
    
    for (int i = 0; i < N; i++) {
        zombies[i].setName(name);
    }
    
    return zombies;
}