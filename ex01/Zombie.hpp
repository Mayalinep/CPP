/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:36:31 by maya              #+#    #+#             */
/*   Updated: 2025/07/22 20:58:52 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
    private:
        std::string name;

    public:
        Zombie();                    // Constructeur par défaut
        Zombie(std::string name);    // Constructeur avec nom
        void setName(std::string name);
        void announce();
        ~Zombie();

};



Zombie* zombieHorde( int N, std::string name );


#endif