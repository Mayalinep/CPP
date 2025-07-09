/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:58:21 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 22:59:56 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP


#include "Weapon.class.hpp"


class HumanB{
    private:
    std::string Name;
    Weapon* weapon;

    public:
    HumanB();
    HumanB(std ::string Name)
    void attack();
};

#endif