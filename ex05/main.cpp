#include "Harl.hpp"

int main() {
	std::cout << std::endl;
    Harl harl;
    
    std::cout << "\n=== Test DEBUG ===" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\n=== Test INFO ===" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\n=== Test WARNING ===" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\n=== Test ERROR ===" << std::endl;
    harl.complain("ERROR");
	std::cout << std::endl;
    
    return 0;
}
