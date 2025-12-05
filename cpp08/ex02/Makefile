NAME =		mutantstack

CC =		c++
CFLAGS = 	-Wall -Wextra -Werror -std=c++98

SRC = 		main.cpp

all: $(NAME)

$(NAME):
	@echo "\033[1m\033[32m[ Compiling ... ]\033[0m"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "\033[1m\033[32m[ 🪄 Program ready! ]\033[0m"

clean:
	@echo "\033[1m\033[31m[ 🔥 Removing program ]\033[0m"
	@rm -f $(NAME)

fclean:
	@echo "\033[1m\033[31m[ 🔥 Removing program ]\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
