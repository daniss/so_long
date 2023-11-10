#include "../includes/so_long.h"

void    initstruct(t_data *mapdata)
{
    mapdata->map.x = 0;
    mapdata->map.y = 0;
    mapdata->map.map = NULL;
    mapdata->win_ptr = NULL;
    mapdata->mlx_ptr = NULL;
    mapdata->map.player_pos = 0;
    mapdata->map.colon = 0;
    mapdata->textures[0] = NULL;
    mapdata->textures[1] = NULL;
    mapdata->textures[2] = NULL;
    mapdata->textures[3] = NULL;
    mapdata->textures[4] = NULL;
    mapdata->textures[5] = NULL;
}


void    initcalc(int colon, int lign, t_data *mapdata, t_map map)
{
    int width;
    int height;
    int x;
    int y;

    x = colon * PX;
    y = lign * PX;
    mapdata->map.x = x;
    mapdata->map.y = y;
    mapdata->win_ptr = mlx_new_window(mapdata->mlx_ptr, x, y, "So_Long");
    mapdata->map.map = map.map;
    mapdata->map.player_pos = map.player_pos;
	mapdata->map.consomable = map.consomable;
    mapdata->map.colon = colon;
    mapdata->textures[0] = mlx_xpm_file_to_image(mapdata->mlx_ptr, "imagesxpm/C.xpm", &width, &height);
    mapdata->textures[1] = mlx_xpm_file_to_image(mapdata->mlx_ptr, "imagesxpm/Pr.xpm", &width, &height);
    mapdata->textures[2] = mlx_xpm_file_to_image(mapdata->mlx_ptr, "imagesxpm/Pl.xpm", &width, &height);
    mapdata->textures[3] = mlx_xpm_file_to_image(mapdata->mlx_ptr, "imagesxpm/0.xpm", &width, &height);
    mapdata->textures[4] = mlx_xpm_file_to_image(mapdata->mlx_ptr, "imagesxpm/1.xpm", &width, &height);
    mapdata->textures[5] = mlx_xpm_file_to_image(mapdata->mlx_ptr, "imagesxpm/Pr.xpm", &width, &height);
}

void    putexture(char *map, t_data mapdata)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while(map[i])
    {
        if(map[i] == '1')
            mlx_put_image_to_window(mapdata.mlx_ptr, mapdata.win_ptr, mapdata.textures[4], x, y);
        if(map[i] == '0')
            mlx_put_image_to_window(mapdata.mlx_ptr, mapdata.win_ptr, mapdata.textures[3], x, y);
        if(map[i] == 'P')
            mlx_put_image_to_window(mapdata.mlx_ptr, mapdata.win_ptr, mapdata.textures[1], x, y);
        if(map[i] == 'C')
            mlx_put_image_to_window(mapdata.mlx_ptr, mapdata.win_ptr, mapdata.textures[0], x, y);
        /*if(map[i] == 'E')
        {
            mlx_put_image_to_window(mapdata.mlx_ptr, mapdata.win_ptr, mapdata.textures[5], x, y);
        }*/
        x += PX;
        if(map[i] == '\n')
        {
            y += PX;
            x = 0;
        }
        i++;
    }
}

void    map_unitialize(int colon, int lign, t_map map)
{
    t_data  mapdata;

    initstruct(&mapdata);
    mapdata.mlx_ptr = mlx_init();
    initcalc(colon, lign, &mapdata, map);
	//free(mapdata.textures[0]);
	//free(mapdata.textures[1]);
    putexture(map.map, mapdata);
    mlx_hook(mapdata.win_ptr, KeyPress, KeyPressMask, handle_key, &mapdata);
    mlx_loop(mapdata.mlx_ptr);
    //lx_loop_hook(mapdata.mlx_ptr, &ft_map_draw, game_init);
    mlx_destroy_window(mapdata.mlx_ptr, mapdata.win_ptr);
    mlx_destroy_display(mapdata.mlx_ptr);
}