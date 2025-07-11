/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:25:05 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/11 21:03:30 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.class.hpp"


HumanA::HumanA(std::string name, Weapon& club) : name(name), club(club){
	
}

void HumanA::attack(){
	std::cout << this->name << " attacks with their " << this->club.getType() << std::endl;
}

HumanA::~HumanA(){
	
}