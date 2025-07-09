/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:03:43 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 20:40:06 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.class.hpp"


Student::Student(){
    this->name = "";
}

Student::Student(std::string name){
    this->name = name;
}

void Student::setName(std::string name){
    this->name = name;
    
}
std::string Student::getName(){
    return this->name;
}

void Student::introduce(){
    std::cout << "Je suis "<< getName() <<std::endl;
}

Student::~Student(){
    std::cout << this->name << " a quitté l'école !"<<std::endl;
}