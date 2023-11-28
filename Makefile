NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
INC			=	-I ./inc -I ./mlx
LIB			=	-L lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	utils/check.c utils/so_long.c utils/utils.c utils/get_next_line_utils.c utils/get_next_line.c \
utils/maps.c utils/error.c utils/parsing.c utils/mapunitialize.c utils/keyhandling.c utils/checkroute.c \
utils/checkconso.c

all:		$(MLX) $(NAME)

$(NAME):	$(OBJ) includes/so_long.h
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@make -s -C mlx

clean:
			@rm -rf $(OBJ) obj

fclean:		clean

			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re