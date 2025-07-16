/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:38:53 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/13 20:53:00 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Book.class.hpp"

Book::Book(std::string title){
	this->title = title;
}

void Book::setTitle(std::string title){
	this->title = title;
}

const std::string& Book::getTitle(){
	return(this->title);
}

Book::~Book(){}