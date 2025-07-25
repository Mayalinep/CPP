# ZOMBIE APOCALYPSE MAKEFILE

# Colors / Emojis 
GREEN = \033[32m
RED = \033[31m
GREY = \033[90m
RESET = \033[0m
ZOMBIE = 🧟
SKULL = 💀
COFFIN = ⚰️

# Name
NAME = zombie_horde

# Compiler & Flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Directories
SRCDIR = ./
OBJDIR = obj

# Files
SRCS = main.cpp Zombie.cpp zombieHorde.cpp display.cpp

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)


all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)$(ZOMBIE) Building the zombie apocalypse...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@echo "$(GREEN)$(ZOMBIE) The zombies are ready!$(RESET)"


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREY)Compiling $<...$(RESET)"


clean:
	@rm -rf $(OBJDIR)
	@rm -f *.o
	@echo "$(RED)$(SKULL) Zombies cleaned up!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(COFFIN) Apocalypse erased!$(RESET)"
re: fclean all

.PHONY: all clean fclean re
