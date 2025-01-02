NAME = push_swap
PATH_SRC = srcs/
PATH_INC = includes/
PATH_LIBFT = libft/
LIBFT_LIB = $(PATH_LIBFT)libft.a
SRC = $(PATH_SRC)main.c $(PATH_SRC)ft_input_ctrl.c $(PATH_SRC)ft_lst_utils.c $(PATH_SRC)operations.c \
		$(PATH_SRC)operations2.c $(PATH_SRC)operations3.c $(PATH_SRC)sorting.c $(PATH_SRC)sorting2.c \
			$(PATH_SRC)split_input.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(PATH_INC) -I $(PATH_LIBFT)

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

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
