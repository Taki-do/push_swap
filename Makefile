NAME = push_swap
PATH_LIBFT = libft/
LIBFT_LIB = $(PATH_LIBFT)libft.a
SRC = src/main.c src/ft_input_ctrl.c src/ft_lst_utils.c src/operations.c \
		src/operations2.c src/operations3.c src/sorting.c src/sorting2.c \
			src/split_input.c src/sorting3.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(PATH_LIBFT)

clean:
	/bin/rm -f $(OBJ)
	make -C $(PATH_LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
