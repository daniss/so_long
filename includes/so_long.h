#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "mlx.h"
# include "mlx_int.h"
# include "get_next_line.h" // changer gnl car c'est pas le mien

# define PX 50
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

typedef struct map
{
	int	exit;
	int	player;
	int	consomable;
	int	wall;
	int player_pos;
	int	colon;
	int	x;
	int	y;
	char *map;
}				t_map;

typedef struct s_data
{
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	void	*textures[5]; // MLX image pointers (on the stack)
	t_map	map;
}				t_data;

//utils
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*get_map(int fd, int *lign, int *colon);
char	*ft_strjoin(char *s1, char *s2);

//check
int	check(int argc, char **argv);
void    error(char *msg);
int   parsingcorrect(t_map *map);

//mapunitialize
void    map_unitialize(int colon, int lign, t_map map);
void    putexture(char *map, t_data mapdata);

//keys
int handle_key(int keysym, t_data *mapdata);

#endif