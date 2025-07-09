/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maya <maya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:58:01 by maya              #+#    #+#             */
/*   Updated: 2025/07/09 20:35:02 by maya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <iostream>
#include <string>

class Student{
    private:
        std::string name;

    public:
        Student();
        Student(std::string name);
        void setName(std::string name);
        std::string getName();
        void introduce();


    ~Student();
};

Student* createClass(int size, std::string defaultName);

#endif