NAME = account 
CLASSES = Account.cpp

all: $(NAME)

$(NAME):
	clang++ -Wall -Wextra -Werror tests.cpp $(CLASSES) -std=c++98 -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all