/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DriverA.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:00:40 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/15 18:03:46 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehicule.class.hpp"


class DriverA{
	private:
		std::string name;
		Vehicule &model;
	public:
		DriverA(std::string name, Vehicule &model);
		const std::string getName();
		void drive();
		~DriverA();
};