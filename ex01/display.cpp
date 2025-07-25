#include "display.hpp"

void typingEffect(const std::string& message, useconds_t delay) {
    for (size_t i = 0; i < message.length(); ++i) {
        std::cout <<GREY<< message[i] << RESET << std::flush;
        usleep(delay);
    }
}

