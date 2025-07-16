/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReaderA.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:24:56 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/14 16:54:27 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReaderA.class.hpp"


ReaderA::ReaderA(std::string name, Book& book) : book(book){
	this->name = name;
}

std::string ReaderA::getName(std::string name){
	return(name);
}
void ReaderA::read(){
	std::cout << getName(name) << " is reading" << book.getTitle() <<std::endl;	
}
		
ReaderA::~ReaderA(){
	std::cout << getName(name) <<" : j'ai fini de lireee!" << std::endl;
}
