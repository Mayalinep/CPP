/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:58:42 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/11 21:23:03 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"


Weapon::Weapon(std::string Type){
	this->Type = Type;
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::Weapon(){
	
}

const std::string& Weapon::getType(){
	return (this->Type);
}

void Weapon::setType(std::string Type){
	this->Type = Type;
}

Weapon::~Weapon(){
	
}