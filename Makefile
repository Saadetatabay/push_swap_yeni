SRC = atoi.c main.c operations.c utils.c utils2.c split.c big_sort.c utils3.c ft_strtrim.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	
fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re