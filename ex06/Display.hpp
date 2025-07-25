#pragma once

#include <unistd.h>
#include <iostream>

//color
#define GREY_COLOR "\033[38;5;245m"
#define COLOR_DEBUG   "\033[38;5;117m"
#define COLOR_INFO    "\033[38;5;121m"
#define COLOR_WARNING "\033[38;5;229m"
#define COLOR_ERROR   "\033[38;5;218m"
#define COLOR_RESET   "\033[0m"


void clignotant_effect(std::string text);
void printProgressBar(int percent);
void typewriter_effect(const std::string& text, useconds_t delay = 40000);