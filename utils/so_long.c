#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_data *mapdata;
	mapdata = malloc(sizeof(t_data));
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
