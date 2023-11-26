/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapunitialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:24 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/26 22:07:12 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	initcalc(t_data *mapdata)
{
	int	w;
	int	h;
	int	x;
	int	y;

	x = mapdata->map.colon * PX;
	y = mapdata->map.lign * PX;
	mapdata->map.x = x;
	mapdata->map.y = y;
	mapdata->mlx.win_ptr = mlx_new_window(mapdata->mlx.mlx_ptr, x, y, "So_Long");
	mapdata->mlx.textures[0] = mlx_xpm_file_to_image(mapdata->mlx.mlx_ptr, "xpm/C.xpm", &w, &h);
	mapdata->mlx.textures[1] = mlx_xpm_file_to_image(mapdata->mlx.mlx_ptr, "xpm/Pr.xpm", &w, &h);
	mapdata->mlx.textures[2] = mlx_xpm_file_to_image(mapdata->mlx.mlx_ptr, "xpm/E.xpm", &w, &h);
	mapdata->mlx.textures[3] = mlx_xpm_file_to_image(mapdata->mlx.mlx_ptr, "xpm/0.xpm", &w, &h);
	mapdata->mlx.textures[4] = mlx_xpm_file_to_image(mapdata->mlx.mlx_ptr, "xpm/1.xpm", &w, &h);
}

void	putexture(t_data *mapdata)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while(mapdata->map.map[i])
	{
		if(mapdata->map.map[i] == '1')
			mlx_put_image_to_window(mapdata->mlx.mlx_ptr, mapdata->mlx.win_ptr, mapdata->mlx.textures[4], x, y);
		if(mapdata->map.map[i] == '0')
			mlx_put_image_to_window(mapdata->mlx.mlx_ptr, mapdata->mlx.win_ptr, mapdata->mlx.textures[3], x, y);
		if(mapdata->map.map[i] == 'P')
			mlx_put_image_to_window(mapdata->mlx.mlx_ptr, mapdata->mlx.win_ptr, mapdata->mlx.textures[1], x, y);
		if(mapdata->map.map[i] == 'C')
			mlx_put_image_to_window(mapdata->mlx.mlx_ptr, mapdata->mlx.win_ptr, mapdata->mlx.textures[0], x, y);
		if(mapdata->map.map[i] == 'E')
			mlx_put_image_to_window(mapdata->mlx.mlx_ptr, mapdata->mlx.win_ptr, mapdata->mlx.textures[2], x, y);
		x += PX;
		if(mapdata->map.map[i] == '\n')
		{
			y += PX;
			x = 0;
		}
		i++;
	}
}

void	map_unitialize(t_data *mapdata)
{
	mapdata->mlx.mlx_ptr = mlx_init();
	initcalc(mapdata);
}