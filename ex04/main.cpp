/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:45:40 by mpelage           #+#    #+#             */
/*   Updated: 2025/07/16 14:35:44 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.class.hpp"

int main(int argc, char **argv){
	
	if(argc == 4){
		std::string filename = argv[1];
		std::string output_filename = filename + ".replace";
		std::ofstream out_file(output_filename.c_str());
		std::string str1 = argv[2];
		std::string str2 = argv[3];
		
		std::ifstream file;
		file.open(argv[1], std:: ifstream::in);
		
		// TODO 1: Vérifier si le fichier s'est bien ouvert
		// INDICE: utilise file.is_open() ou !file
		// Si erreur, affiche un message et return 1
		if(!file.is_open()){
			std::cerr << "Error opening file" <<std::endl;
			return 1;
		}

		std::string line;
		std::string content;
		while(std::getline(file, line)){

			content += line + "\n";
		}
		
		std::size_t found = content.find(str1);
		while(found != std::string::npos){
			content.insert(found, str2);                    // Insert str2
			content.erase(found + str2.length(), str1.length());  // Supprime str1
			found = content.find(str1, found + str2.length());
		}
		out_file << content;
		out_file.close();
		file.close();
		return 0;
		
	}
	else{
		std::cout << "Mauvais nbr d'arguments" << std::endl;
		return(1);
	}
	return 0;
}
