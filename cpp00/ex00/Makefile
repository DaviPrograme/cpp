NAME = megaphone 

all: $(NAME)

$(NAME):
	clang++ -Wall -Wextra -Werror megaphone.cpp -std=c++98 -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all