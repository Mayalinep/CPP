/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReaderB.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:06:44 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/13 20:58:03 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Book.class.hpp"


class ReaderB{
	private:
		std::string name;
		Book* book;

	public:
		ReaderB(std::string name);
		std::string getName(std::string name);
		void setBook(Book& book);
		void read();


	~ReaderB();
};