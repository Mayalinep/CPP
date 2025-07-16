/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReaderA.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:12:26 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/13 20:48:01 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Book.class.hpp"

class ReaderA{
	private:
		std::string name;
		Book& book;


	public:
		ReaderA(std::string name, Book& book);
		std::string getName(std::string name);
		void read();
		~ReaderA();
};