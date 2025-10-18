SRC = atoi.c main.c operations.c utils.c utils2.c split.c big_sort.c utils3.c ft_strtrim.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = push_swap.a

NAME = push_swap

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)


clean : 
		rm -f $(OBJ)
	
fclean : clean
		rm -f $(NAME) $(LIB)

re : fclean all

.PHONY : all clean fclean re