# 🧟‍♂️ ZOMBIE APOCALYPSE MAKEFILE

# === Colors & Emojis ===
GREEN = \033[32m
RED = \033[31m
GREY = \033[90m
RESET = \033[0m
ZOMBIE = 🧟
SKULL = 💀
COFFIN = ⚰️

# === Compiler & Flags ===
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# === Files ===
NAME = zombie
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp display.cpp
OBJS = $(SRCS:%.cpp=obj/%.o)

# === Rules ===
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)$(ZOMBIE) Building the zombie apocalypse...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@echo "$(GREEN)$(ZOMBIE) The zombies are ready!$(RESET)"

obj/%.o: %.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREY)Compiling $<...$(RESET)"

clean:
	@rm -rf obj
	@rm -f *.o
	@echo "$(RED)$(SKULL) Zombies cleaned up!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(COFFIN) Apocalypse erased!$(RESET)"

re: fclean all

.PHONY: all clean fclean re 