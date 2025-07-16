/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Book.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:08:55 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/13 20:53:15 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Book{
	private:
		std::string title;

	public:
		Book(std::string title);
		const std::string& getTitle();
		void setTitle(std::string title);

		~Book();
};