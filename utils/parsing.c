#include "../includes/so_long.h"

t_map   unitializeandparse(t_map parsing, char *map)
{
    int i;

    i = 0;
    parsing.consomable = 0;
    parsing.exit = 0;
    parsing.player = 0;
    parsing.wall = 0;
	parsing.player_pos;
    while(map[i])
    {
        if(map[i] == '1')
            parsing.wall += 1;
        if(map[i] == 'E')
            parsing.exit += 1;
        if(map[i] == 'P')
        {
            parsing.player += 1;
            parsing.player_pos = i;
        }
        if(map[i] == 'C')
            parsing.consomable += 1;
        i++;
    }
    return(parsing);
}

int   parsingcorrect(t_map *map)
{
    int     i;

    *map = unitializeandparse(*map, map->map);
    i = 0;
    while(map->map[i] && map->map != NULL)
    {
        if (map->map[i] != '1' && map->map[i] != '0' && map->map[i] != 'E' && map->map[i] != 'P' && map->map[i] != 'C' && map->map[i] != '\n')
            return (0);
        i++;
    }
    if (map->exit != 1 || map->player != 1 || map->consomable < 1)
        return(0);
}