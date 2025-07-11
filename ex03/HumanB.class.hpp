/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:58:21 by maya              #+#    #+#             */
/*   Updated: 2025/07/11 21:07:41 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP


#include "Weapon.class.hpp"


class HumanB{
    private:
    std::string name;
    Weapon* weapon;

    public:
    HumanB(std::string name);
    void attack();
	void setWeapon(Weapon& weapon);
	~HumanB();
};

#endif