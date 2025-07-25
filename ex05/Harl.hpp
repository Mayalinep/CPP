#pragma once

#include <iostream>
#include <string>

//colors
#define COLOR_DEBUG   "\033[38;5;110m"
#define COLOR_INFO    "\033[38;5;108m"
#define COLOR_WARNING "\033[38;5;229m"
#define COLOR_ERROR   "\033[38;5;210m"
#define COLOR_RESET   "\033[0m"

class Harl{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		void complain(std::string level);
		~Harl();
	
};