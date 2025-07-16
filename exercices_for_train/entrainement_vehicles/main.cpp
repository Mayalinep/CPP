/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:24:32 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/15 18:28:22 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DriverB.class.hpp"
#include "Vehicule.class.hpp"
#include "DriverA.class.hpp"


int main(){
    {
        Vehicule car = Vehicule("Ferrari");
        DriverA alice("Alice", car);
        alice.drive();
        car.setModel("Lamborghini");
        alice.drive();
    }
    {
        Vehicule car = Vehicule("Ferrari");
        DriverB bob("Bob");
        bob.drive();  // Bob has no vehicle
        bob.setVehicule(car);
        bob.drive();
        car.setModel("Lamborghini");
        bob.drive();
    }
    return 0;
}