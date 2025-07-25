#include "Replace.hpp"

//initialization
Replace::Replace(const std::string& filename, const std::string& str1, const std::string& str2, const std::string& output_filename)
    : _filename(filename), _str1(str1), _str2(str2), _output_filename(output_filename), _nb_replacements(0)
{
    std::cout << GREEN << "Initializing the Program Sed_is_for_losers ... " << RESET << std::endl << std::endl;
}

//replace_content
void Replace::replace_content()
{
	//Verification
    std::ifstream file(_filename.c_str());
    if (!file.is_open()) {
        std::cerr << RED << "Error: The file could not be opened." << RESET << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << RED << "Error: The file is empty." << RESET << std::endl;
        return;
    }
    if (_str1.empty()) {
        std::cerr << RED << "Error: The string to replace is empty." << RESET << std::endl;
        return;
    }
    if (_str2.empty()) {
        std::cerr << RED << "Error: The string to replace with is empty." << RESET << std::endl;
        return;
    }
    if (_str1 == _str2) {
        std::cerr << RED << "Error: The string to replace is the same as the string to replace with." << RESET << std::endl;
        return;
    }
	//Replace
    std::string line, output_content;
    _nb_replacements = 0;
    while (std::getline(file, line)) {
        std::size_t found = line.find(_str1); // find the 1er occurence of _str1 in line
        while (found != std::string::npos) { // tant que l'on trouve des occurences de _str1 dans line
            line.insert(found, _str2); // insert _str2 at the position found
            line.erase(found + _str2.length(), _str1.length());
            found = line.find(_str1, found + _str2.length()); // find the next occurence
            _nb_replacements++;
        }
        output_content += line + "\n"; // add the line to the output_content
    }
    file.close();

    if (_nb_replacements > 0) {
        std::ofstream out_file(_output_filename.c_str()); // create the output file
        if (!out_file.is_open()) {
            std::cerr << RED << "Error: The output file could not be created." << RESET << std::endl;
            return;
        }
        out_file << output_content; // 
        out_file.close();
        std::cout << "\nReplacement successful !" << std::endl;
        std::cout << "Original file : " << _filename << std::endl;
        std::cout << "Modified file  : " << _output_filename << std::endl;
        std::cout << "Total number of replacements : " << _nb_replacements << std::endl;
        std::cout << "Replacement : '" << _str1 << "' => '" << _str2 << "'" << std::endl << std::endl;
    } else {
        std::cout << RED << "No replacement has been made." << RESET << std::endl;
        std::cout << "And the " << _output_filename << " file has not been created." << std::endl;
    }
}

int Replace::getNbReplacements() const
{
    return _nb_replacements;
}

Replace::~Replace() {}