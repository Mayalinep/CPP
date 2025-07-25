/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:47:53 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/24 18:17:55 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

// color
# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

class Replace{
	private:
		const std::string _filename; // the file to replace
		const std::string _str1; // argv1
		const std::string _str2; // argv2
		const std::string _output_filename; // the nqme + .replace
		int _nb_replacements; 

	public:
		//constructor
		Replace(const std::string& filename, const std::string& str1, const std::string& str2, const std::string& output_filename);
		//replace_content
		void replace_content();
		//getters
		int getNbReplacements() const;
		~Replace();
};

