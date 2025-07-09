/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:52:15 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 13:19:13 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int main()
{
    randomChump("Bob");
    Zombie* zombie = newZombie("audrey");
    zombie->announce();
    delete zombie;
    return (0);
}