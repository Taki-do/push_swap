NAME = push_swap
PATH_SRC = srcs/
PATH_INC = includes/
PATH_LIBFT = libft/
LIBFT_LIB = $(PATH_LIBFT)libft.a
SRC = 
SRC_BONUS = 
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT_LIB):
	make -C $(PATH_LIBFT)

bonus : $(LIBFT_LIB) $(OBJ) $(OBJ_BONUS)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

$(NAME) : $(LIBFT_LIB) $(OBJ) 
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	/bin/rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(PATH_LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus