#pragma once

#include <string>
#include <iostream>

#define NIGHT_BLUE   "\033[38;2;44;62;80m"
#define SILVER      "\033[38;2;200;200;220m"
#define DEEP_VIOLET "\033[38;2;120;80;180m"
#define MOON_CYAN   "\033[38;2;80;200;220m"
#define BLUE_GREY   "\033[38;2;120;130;150m"
#define RESET       "\033[0m"

class Weapon{
    private:
        std::string type ;


    public:
		Weapon();
		Weapon(std::string Type);
		const std::string& getType();
		void setType(std::string Type);
		~Weapon();
};
