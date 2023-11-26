NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./mlx
LIB			=	-L lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	utils/check.c utils/so_long.c utils/utils.c utils/get_next_line_utils.c utils/get_next_line.c \
utils/maps.c utils/error.c utils/parsing.c utils/mapunitialize.c utils/keyhandling.c utils/checkroute.c \
utils/checkconso.c

all:		$(MLX) obj $(NAME)

$(NAME):	$(OBJ) includes/so_long.h
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:

			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean

			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re