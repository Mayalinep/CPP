/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:51:00 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 12:52:20 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie(std::string name){
    this->name = name;
}
void Zombie::announce()
{
 std::cout << name <<" : BraiiiiiiinnnzzzZ..."<< std::endl;
}
Zombie::~Zombie(){
    std::cout << name << " détruit!" << std::endl;
}
