/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DriverA.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:03:56 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/15 18:32:05 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DriverA.class.hpp"


DriverA::DriverA(std::string name, Vehicule &model): name(name), model(model){
	
}

const std::string DriverA::getName(){
	return(name);
}

void DriverA::drive(){
	std::cout << getName() << " drives a " << model.getModel() << std::endl;
}

DriverA::~DriverA(){
	
}