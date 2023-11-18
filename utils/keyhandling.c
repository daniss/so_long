#include "../includes/so_long.h"

int	freeall(t_data *mapdata)
{
	mlx_destroy_image(mapdata->mlx.mlx_ptr, mapdata->mlx.textures[0]);
	mlx_destroy_image(mapdata->mlx.mlx_ptr, mapdata->mlx.textures[1]);
	mlx_destroy_image(mapdata->mlx.mlx_ptr, mapdata->mlx.textures[2]);
	mlx_destroy_image(mapdata->mlx.mlx_ptr, mapdata->mlx.textures[3]);
	mlx_destroy_image(mapdata->mlx.mlx_ptr, mapdata->mlx.textures[4]);
	mlx_destroy_image(mapdata->mlx.mlx_ptr, mapdata->mlx.textures[5]);
	mlx_destroy_window(mapdata->mlx.mlx_ptr, mapdata->mlx.win_ptr);
	mlx_destroy_display(mapdata->mlx.mlx_ptr); // double free or corruption
	free(mapdata->mlx.mlx_ptr);
	free(mapdata->map.map);
	free(mapdata);
	exit (EXIT_FAILURE);
}
void   player_move(t_data *mapdata, int depla)
{
	int temp;

	if (mapdata->map.map[mapdata->map.player_pos + depla] == 'E' && mapdata->map.consomable == 0)
	{
		freeall(mapdata);
		return ;
	}
	if (mapdata->map.map[mapdata->map.player_pos + depla] != '1' && mapdata->map.map[mapdata->map.player_pos + depla] != 'E')
	{
		mapdata->map.count++;
		write(1, "number of mouvements : ", 24);
		ft_putnbr_fd(mapdata->map.count, 1);
		write(1, "\n", 1);
		temp = mapdata->map.player_pos;
		if (mapdata->map.map[mapdata->map.player_pos + depla] == 'C')
			mapdata->map.consomable = mapdata->map.consomable - 1;
		mapdata->map.map[mapdata->map.player_pos + depla] = 'P';//player_move(mapdata); //RIGHT;
		mapdata->map.map[temp] = '0';
		mapdata->map.player_pos += depla;
	}
}

int handle_key(int keysym, t_data *mapdata)
{
	if (keysym == KEY_UP || keysym == KEY_W)
	{
		player_move(mapdata, -(mapdata->map.colon)-1);
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
		player_move(mapdata, mapdata->map.colon+1);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		freeall(mapdata);
	//mlx_clear_window(mapdata->mlx.mlx_ptr, mapdata->mlx.win_ptr);
	putexture(mapdata);
	return (0);
}