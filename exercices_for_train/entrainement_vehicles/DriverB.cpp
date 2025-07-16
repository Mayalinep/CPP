/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DriverB.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:09:53 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/15 18:49:33 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DriverB.class.hpp"

DriverB::DriverB(std::string name) : name(name), model(NULL){
	
}


const std::string DriverB::getName(){
	return(name);
}

void DriverB::setVehicule(Vehicule& vehicule){
	this->model = &vehicule;
}

void DriverB::drive(){
	if(model)
		std::cout << getName() << " drives a " << model->getModel() << std::endl;
	else
		std::cout << getName() << " has no vehicule " << std::endl;
}

DriverB::~DriverB(){
	
}