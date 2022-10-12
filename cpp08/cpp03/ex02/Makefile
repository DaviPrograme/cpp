NAME = ex02 
FILES = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror main.cpp $(FILES) -std=c++98 -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all