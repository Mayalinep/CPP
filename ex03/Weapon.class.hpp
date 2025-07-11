/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:49:27 by maya              #+#    #+#             */
/*   Updated: 2025/07/11 20:13:04 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>
#include <iostream>

class Weapon{
    private:
        std::string Type ;


    public:
    Weapon();
    Weapon(std::string Type);
    const std::string& getType();
    void setType(std::string Type);
	~Weapon();
};


#endif