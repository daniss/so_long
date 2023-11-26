/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:37 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/26 23:52:13 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	freeall(t_data *mapdata)
{
	mlx_destroy_image(mapdata->ml.m, mapdata->ml.t[0]);
	mlx_destroy_image(mapdata->ml.m, mapdata->ml.t[1]);
	mlx_destroy_image(mapdata->ml.m, mapdata->ml.t[2]);
	mlx_destroy_image(mapdata->ml.m, mapdata->ml.t[3]);
	mlx_destroy_image(mapdata->ml.m, mapdata->ml.t[4]);
	mlx_destroy_window(mapdata->ml.m, mapdata->ml.w);
	mlx_destroy_display(mapdata->ml.m);
	free(mapdata->ml.m);
	free(mapdata->map.map);
	free(mapdata);
	exit (EXIT_FAILURE);
}

void	player_move(t_data *mapdata, int depla)
{
	int	temp;

	if (mapdata->map.map[mapdata->map.player_pos + depla] == 'E'
		&& mapdata->map.consomable == 0)
	{
		freeall(mapdata);
		return ;
	}
	if (mapdata->map.map[mapdata->map.player_pos + depla] != '1'
		&& mapdata->map.map[mapdata->map.player_pos + depla] != 'E')
	{
		mapdata->map.count++;
		write(1, "number of mouvements : ", 23);
		ft_putnbr_fd(mapdata->map.count, 1);
		write(1, "\n", 1);
		temp = mapdata->map.player_pos;
		if (mapdata->map.map[mapdata->map.player_pos + depla] == 'C')
			mapdata->map.consomable = mapdata->map.consomable - 1;
		mapdata->map.map[mapdata->map.player_pos + depla] = 'P';
		mapdata->map.map[temp] = '0';
		mapdata->map.player_pos += depla;
	}
}

int	handle_key(int keysym, t_data *mapdata)
{
	if (keysym == KEY_UP || keysym == KEY_W)
	{
		player_move(mapdata, -(mapdata->map.colon) - 1);
	}
	if (keysym == KEY_LEFT || keysym == KEY_A)
	{
		player_move(mapdata, -1);
	}
	if (keysym == KEY_RIGHT || keysym == KEY_D)
	{
		player_move(mapdata, 1);
	}
	if (keysym == KEY_DOWN || keysym == KEY_S)
		player_move(mapdata, mapdata->map.colon + 1);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		freeall(mapdata);
	putexture(mapdata);
	return (0);
}
