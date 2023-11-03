#include "../includes/so_long.h"

t_map   unitializeandparse(t_map parsing, char *map)
{
    int i;

    i = 0;
    parsing.consomable = 0;
    parsing.exit = 0;
    parsing.player = 0;
    parsing.wall = 0;
    while(map[i])
    {
        if(map[i] == '1')
            parsing.wall += 1;
        if(map[i] == 'E')
            parsing.exit += 1;
        if(map[i] == 'P')
            parsing.player += 1;
        if(map[i] == 'C')
            parsing.consomable += 1;
        i++;
    }
    return(parsing);
}

int   parsingcorrect(char *map)
{
    t_map   parsing;
    int     i;

    parsing = unitializeandparse(parsing, map);
    i = 0;
    while(map[i] && map != NULL)
    {
        if (map[i] != '1' && map[i] != '0' && map[i] != 'E' && map[i] != 'P' && map[i] != 'C' && map[i] != '\n')
            return (0);
        i++;
    }
    if (parsing.exit != 1 || parsing.player != 1 || parsing.consomable < 1)
        return(0);
}