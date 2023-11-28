/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:46:28 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/19 11:46:28 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "get_next_line.h"

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

typedef struct s_map
{
	int		exit;
	int		player;
	int		consomable;
	int		wall;
	int		player_pos;
	int		lign;
	int		colon;
	int		x;
	int		y;
	int		count;
	char	*map;
}				t_map;

typedef struct s_mlx
{
	void	*m;
	void	*w;
	void	*t[5];
}				t_mlx;

typedef struct s_maparray
{
	char	**maparray;
	int		x;
	int		y;
	int		consomable;
}				t_maparray;

typedef struct s_data
{
	t_map	map;
	t_mlx	ml;
}				t_data;

//utils
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		get_map(int fd, t_data *mapdata);
char	*ft_strjoin(char *s1, char *s2);
int		freeall(t_data *mapdata);
int		ft_strlen(char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

//check
void	check(int argc, char **argv, t_data *mapdata);
void	error(char *msg);
int		parsingcorrect(t_data *mapdata);
int		check_path(char *argv, int lign);
int		check_conso(char *argv, int lign, int conso);

//mapunitialize
void	map_unitialize(t_data *map);
void	putexture(t_data *mapdata);

//keys
int		handle_key(int keysym, t_data *mapdata);

#endif