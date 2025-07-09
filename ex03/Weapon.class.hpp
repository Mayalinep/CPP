/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:49:27 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 23:00:23 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>
#include <iostream>

class Weapon{
    private:
        cst std::string Type ;


    public:
    Weapon();
    Weapon(std::string Type);
    std::string getType();
    void setType(std::string Type);
};


#endif