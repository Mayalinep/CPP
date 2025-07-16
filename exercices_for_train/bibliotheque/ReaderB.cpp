/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReaderB.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:32:09 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/14 16:54:58 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReaderB.class.hpp"

ReaderB::ReaderB(std::string name): name(name), book(NULL){

	
}

void ReaderB::setBook(Book& book){
	this->book = &book;
}

std::string ReaderB::getName(std::string name){
	return(name);
}
void ReaderB::read(){
 if(this->book != NULL){
	std::cout << getName(name) << " is reading " << book->getTitle() << std::endl;
 }
 else
	std::cout << getName(name) << " has no book!" << std::endl;
}

ReaderB::~ReaderB(){
	std::cout << getName(name) << " : j'ai fini de lireee!" << std::endl;
}