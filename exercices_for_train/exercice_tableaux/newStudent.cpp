/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newStudent.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:12:06 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 20:39:53 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.class.hpp"


Student* createClass(int size, std::string defaultName){
    Student* students = new Student[size];

    for (int i = 0; i < size; i++) {
        students[i].setName(defaultName);
    }
    return students;
}
