SRCS = utils/check.c utils/so_long.c utils/utils.c utils/get_next_line_utils.c utils/get_next_line.c \
	   utils/maps.c utils/error.c utils/parsing.c

NAME = so_long

# Spécifiez les répertoires où se trouvent les fichiers d'en-tête et les bibliothèques de la MinilibX
MLX_DIR = mlx
MLX_LIB = -L$(MLX_DIR) -lmlx_linux -lX11 -lXext -lm
MLX_INC = -I$(MLX_DIR)

# Ajoutez les drapeaux de compilation et de liaison de la MinilibX
CFLAGS = $(MLX_INC) #-Wall -Wextra -Werror 
LDFLAGS = $(MLX_LIB)

# Règle de compilation
.c.o:
	gcc $(CFLAGS) -c $< -o $@

# Règle de liaison
$(NAME): $(SRCS:.c=.o)
	gcc $(LDFLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	rm -f $(SRCS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
