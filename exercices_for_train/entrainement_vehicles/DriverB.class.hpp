/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DriverB.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:08:04 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/15 18:51:24 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehicule.class.hpp"

class DriverB{
	private:
		std::string name;
		Vehicule* model;
		
	public:
		DriverB(std::string name);
		void drive();
		const std::string getName();
		void setVehicule(Vehicule& vehicule);
		~DriverB();
};