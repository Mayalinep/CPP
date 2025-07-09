/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:13 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 20:07:06 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

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
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructeur avec nom
Zombie::~Zombie() {
    std::cout << this->name << " détruit!" << std::endl;
}