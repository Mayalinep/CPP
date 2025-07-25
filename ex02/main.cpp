/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:07:43 by maya              #+#    #+#             */
/*   Updated: 2025/07/23 15:46:03 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(){

	std::cout << std::endl;
    std::string scream = "HI THIS IS BRAIN";
    std::string* stringPTR = &scream;
    std::string& stringREF = scream;

    //Display Address
	std::cout << "Address of the string: " << std::endl;
    std::cout << &scream << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

	std::cout << std::endl;

    //Display Value
	std::cout << "Value of the string: " << std::endl;
    std::cout << scream << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    return (0);
}