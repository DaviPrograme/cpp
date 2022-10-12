NAME = agenda 
CLASSES = Contact.cpp  PhoneBook.cpp

all: $(NAME)

$(NAME):
	clang++ -Wall -Wextra -Werror main.cpp $(CLASSES) -std=c++98 -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all