/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:09 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/19 11:45:09 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_data *mapdata;

	mapdata = malloc(sizeof(t_data));
	if(!mapdata)
		error("Malloc error!\n");
	mapdata->map.count = 0;
	check(argc, argv, mapdata);
	map_unitialize(mapdata);
	putexture(mapdata);
	mlx_hook(mapdata->mlx.win_ptr, KeyPress, KeyPressMask, handle_key, mapdata);
	mlx_hook(mapdata->mlx.win_ptr, DestroyNotify, ButtonPressMask, freeall, mapdata);
	mlx_loop(mapdata->mlx.mlx_ptr);
	freeall(mapdata);
	return 0;
}
