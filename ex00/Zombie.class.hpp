/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:28:40 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 12:29:19 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <string>
#include <iostream>

class Zombie{
    private:
        std::string name;


    public:
    Zombie(std::string name);
    void announce();
    ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif