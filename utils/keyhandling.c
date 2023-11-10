#include "../includes/so_long.h"

void	freeall(t_data *mapdata)
{
	mlx_destroy_image(mapdata->mlx_ptr, mapdata->textures[0]);
	mlx_destroy_image(mapdata->mlx_ptr, mapdata->textures[1]);
	mlx_destroy_image(mapdata->mlx_ptr, mapdata->textures[2]);
	mlx_destroy_image(mapdata->mlx_ptr, mapdata->textures[3]);
	mlx_destroy_image(mapdata->mlx_ptr, mapdata->textures[4]);
	mlx_destroy_image(mapdata->mlx_ptr, mapdata->textures[5]);
	mlx_destroy_window(mapdata->mlx_ptr, mapdata->win_ptr);
	mlx_destroy_display(mapdata->mlx_ptr);
	free(mapdata->mlx_ptr);
	free(mapdata->map.map);
}
t_data    *player_move(t_data *newmap, int depla)
{
	int temp;

	if (newmap->map.map[newmap->map.player_pos + depla] == 'E' && newmap->map.consomable == 0)
	{
		mlx_clear_window(newmap->mlx_ptr, newmap->win_ptr);
		//freeall(newmap);
		exit(0);
	}
	if (newmap->map.map[newmap->map.player_pos + depla] != '1' && newmap->map.map[newmap->map.player_pos + depla] != 'E')
	{
		temp = newmap->map.player_pos;
		if (newmap->map.map[newmap->map.player_pos + depla] == 'C')
			newmap->map.consomable = newmap->map.consomable - 1;
		newmap->map.map[newmap->map.player_pos + depla] = 'P';//player_move(newmap); //RIGHT;
		newmap->map.map[temp] = '0';
		newmap->map.player_pos += depla;
	}
	return(newmap);
}

int handle_key(int keysym, t_data *mapdata)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		mapdata = player_move(mapdata, -(mapdata->map.colon)-1);
	if (keysym == KEY_LEFT || keysym == KEY_A)
	{
		mapdata = player_move(mapdata, -1);
		mapdata->textures[1] = mapdata->textures[2];
	}
	if (keysym == KEY_RIGHT || keysym == KEY_D)
	{
		mapdata = player_move(mapdata, 1);
		mapdata->textures[1] = mapdata->textures[5];
	}
	if (keysym == KEY_DOWN || keysym == KEY_S)
		mapdata = player_move(mapdata, mapdata->map.colon+1);
	if (keysym == KEY_Q || keysym == KEY_ESC)
	{
		freeall(mapdata);
		exit(0);
	}
	mlx_clear_window(mapdata->mlx_ptr, mapdata->win_ptr);
	putexture(mapdata->map.map, *mapdata);
	return (0);
}