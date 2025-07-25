#pragma once

#include <iostream>
#include <unistd.h>
#include <string>
#include "Zombie.hpp"

// color
#define RED "\033[31m"
#define GREY "\033[90m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void typingEffect(const std::string& message, useconds_t delay);