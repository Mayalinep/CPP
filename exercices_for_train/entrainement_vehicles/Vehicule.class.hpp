/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehicule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:17:41 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/15 19:41:35 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>


class Vehicule{
	private:
		std::string model;
		

	public:
		Vehicule(std::string model);
		void setModel(std::string model);
		const std::string& getModel();
		~Vehicule();
};