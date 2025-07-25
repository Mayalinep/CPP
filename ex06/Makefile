# Colors
RESET = \033[0m
GREEN = \033[32m
RED = \033[31m
GREY = \033[90m

# Name
NAME = harlFilter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp Harl.cpp Display.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

HEADERS = Harl.hpp Display.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)Program compiled!$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@echo "$(GREY)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(RED)Program erased!$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Program completly erased!$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 