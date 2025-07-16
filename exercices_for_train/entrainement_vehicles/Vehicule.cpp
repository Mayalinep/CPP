/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehicule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:54:05 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/15 18:31:35 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehicule.class.hpp"

Vehicule::Vehicule(std::string model): model(model){
	
}

void Vehicule::setModel(std::string model){
	this->model = model;
}

const std::string& Vehicule::getModel(){
	return(model);
}

Vehicule::~Vehicule(){
	
}