/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:56:11 by maya              #+#    #+#             */
/*   Updated: 2025/07/23 16:43:35 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP


#include "Weapon.hpp"


class HumanA{
    private:
        std::string name ;
        Weapon& club;

    public:
	
        HumanA(std::string name, Weapon &club);
		
        void attack();
		
	~HumanA();
};

#endif