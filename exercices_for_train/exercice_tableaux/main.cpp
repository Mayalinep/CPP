/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:11:17 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 20:39:44 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.class.hpp"

int main(){
    int Size = 3;
    Student* student = createClass(Size, "Etudiant");
    student[0].setName("Alice");
    student[1].setName("Bob");
    for(int i = 0; i< Size; i++){
        student[i].introduce();
    }
    
    delete[] student;
    return(0); 
}