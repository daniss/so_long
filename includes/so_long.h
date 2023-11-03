#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

typedef struct map
{
	int	exit;
	int	player;
	int	consomable;
	int	wall;
}				t_map;

//utils
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*get_map(int fd, int *lign, int *colon);

//check
int	check(int argc, char **argv);
void    error(char *msg);
int   parsingcorrect(char *map);

#endif