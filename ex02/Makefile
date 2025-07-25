# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 21:22:32 by maya              #+#    #+#              #
#    Updated: 2025/07/23 15:49:31 by mpelage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colors
RESET = \033[0m
GREEN = \033[32m
RED = \033[31m

# Name
NAME = brain

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .

OBJDIR = obj

SOURCES = main.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)Program compiled!$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)


clean:
	@echo "$(RED)Program erased!$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Program completly erased!$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re