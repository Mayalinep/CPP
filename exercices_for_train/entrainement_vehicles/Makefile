# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 17:17:20 by mpelage           #+#    #+#              #
#    Updated: 2025/07/15 18:26:52 by mpelage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vehicles

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = ./
OBJDIR = obj/

SOURCES = main.cpp \
		  Vehicule.cpp \
		  DriverA.cpp \
		  DriverB.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
