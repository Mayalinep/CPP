#include "Replace.hpp"

int main(int argc, char **argv){
    if(argc != 4){
		std::cout << std::endl;
        std::cout << "You need to give 3 arguments: ./replace <filename> <s1> <s2>" << std::endl;
		std::cout << std::endl;
        return 1;
    }
	std::cout << std::endl;
	std::cout << " ╔══════════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << " ║           Welcome to the advanced replacement program !              ║" << std::endl;
	std::cout << " ║              Because we are not like the others                      ║" << std::endl;
	std::cout << " ║                                                                      ║" << std::endl;
	std::cout << " ║            Usage: ./replace <filename> <s1> <s2>                     ║" << std::endl;
	std::cout << " ║                                                                      ║" << std::endl;
	std::cout << " ║         Example: ./replace hello.txt \"hello\" \"world\"                 ║" << std::endl;
	std::cout << " ║                                                                      ║" << std::endl;
	std::cout << " ║ The program will replace all occurrences of \"hello\" with \"world\"     ║" << std::endl;
	std::cout << " ╚══════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;

    Replace replace(argv[1], argv[2], argv[3], std::string(argv[1]) + ".replace");
    replace.replace_content();
    return 0;
}
