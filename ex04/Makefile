
# colors
RESET = \033[0m
GREEN = \033[32m
RED = \033[31m
GREY = \033[90m

# Name
NAME = Not_a_Looser

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp Replace.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

HEADERS = Replace.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)Program compiled!$(RESET)"
	@echo "$(GREEN) I am  $(NAME)$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
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
	@rm -f *.replace

re: fclean all

.PHONY: all clean fclean re
