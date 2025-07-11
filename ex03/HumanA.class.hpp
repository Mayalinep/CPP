/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:56:11 by maya              #+#    #+#             */
/*   Updated: 2025/07/11 20:20:19 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP


#include "Weapon.class.hpp"


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