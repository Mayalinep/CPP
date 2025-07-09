/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:57:52 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 14:17:53 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int main() {
    int N = 4;
    Zombie* horde = zombieHorde(N, "Bob");  // Appel de fonction
    
    // Test chaque zombie
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    
    delete[] horde;  // IMPORTANT : delete[] pour tableau !
    return 0;
}