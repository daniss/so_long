/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapunitialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:24 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/26 23:47:41 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	initcalc(t_data *md)
{
	int	w;
	int	h;
	int	x;
	int	y;

	x = md->map.colon * PX;
	y = md->map.lign * PX;
	md->map.x = x;
	md->map.y = y;
	md->ml.w = mlx_new_window(md->ml.m, x, y, "So_Long");
	md->ml.t[0] = mlx_xpm_file_to_image(md->ml.m, "x/C.xpm", &w, &h);
	md->ml.t[1] = mlx_xpm_file_to_image(md->ml.m, "x/Pr.xpm", &w, &h);
	md->ml.t[2] = mlx_xpm_file_to_image(md->ml.m, "x/E.xpm", &w, &h);
	md->ml.t[3] = mlx_xpm_file_to_image(md->ml.m, "x/0.xpm", &w, &h);
	md->ml.t[4] = mlx_xpm_file_to_image(md->ml.m, "x/1.xpm", &w, &h);
}

void	putexture(t_data *m)
{
	int			i;
	t_maparray	xy;

	i = 0;
	xy.x = 0;
	xy.y = 0;
	while (m->map.map[i])
	{
		if (m->map.map[i] == '1')
			mlx_put_image_to_window(m->ml.m, m->ml.w, m->ml.t[4], xy.x, xy.y);
		if (m->map.map[i] == '0')
			mlx_put_image_to_window(m->ml.m, m->ml.w, m->ml.t[3], xy.x, xy.y);
		if (m->map.map[i] == 'P')
			mlx_put_image_to_window(m->ml.m, m->ml.w, m->ml.t[1], xy.x, xy.y);
		if (m->map.map[i] == 'C')
			mlx_put_image_to_window(m->ml.m, m->ml.w, m->ml.t[0], xy.x, xy.y);
		if (m->map.map[i] == 'E')
			mlx_put_image_to_window(m->ml.m, m->ml.w, m->ml.t[2], xy.x, xy.y);
		xy.x += PX;
		if (m->map.map[i++] == '\n')
		{
			xy.y += PX;
			xy.x = 0;
		}
	}
}

void	map_unitialize(t_data *mapdata)
{
	mapdata->ml.m = mlx_init();
	initcalc(mapdata);
}
