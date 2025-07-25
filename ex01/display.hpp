#pragma once

#include <iostream>
#include <string>
#include <unistd.h>


#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define GREY "\033[90m"

void typingEffect(const std::string& message, useconds_t delay);
