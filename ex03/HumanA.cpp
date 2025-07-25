/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:25:05 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/23 17:26:51 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& club) : name(name), club(club){
	
	std::cout << SILVER << name << RESET << " is ready for the fight and brandishing his " << club.getType() << std::endl;
}

void HumanA::attack(){
	std::cout << std::endl;
	std::cout << DEEP_VIOLET << this->name << " attacks with their " << this->club.getType() << RESET << std::endl;
}

HumanA::~HumanA(){
	std::cout << std::endl;
	std::cout << std::endl;
	
}