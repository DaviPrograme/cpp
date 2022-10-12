NAME = replace
FILES = replace.cpp 

all: $(NAME)

$(NAME):
	clang++ -Wall -Wextra -Werror main.cpp $(FILES) -std=c++98 -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all