/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:56:11 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 22:57:29 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP


#include "Weapon.class.hpp"


class HumanA{
    private:
        std::string Name ;
        Weapon &club;



    public:
        HumanA();
        HumanA(std::string Name, Weapon &club);
        void attack();
};

#endif