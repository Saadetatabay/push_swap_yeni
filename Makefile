SRC = atoi.c main.c operations.c utils.c utils2.c split.c big_sort.c utils3.c

CC = cc

FLAGS = -Wall -Wextra -Werror

LIB = pushswap.a

NAME = pushswap

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
		rm -f $(OBJ)
	
fclean : clean
		rm -f $(NAME) $(LIB)

re : fclean all

.PHONY : all clean fclean re