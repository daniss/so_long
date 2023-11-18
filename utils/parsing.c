#include "../includes/so_long.h"

void   unitializeandparse(t_data *datamap)
{
	int i;

	i = 0;
	datamap->map.consomable = 0;
	datamap->map.exit = 0;
	datamap->map.player = 0;
	datamap->map.wall = 0;
	datamap->map.player_pos;
	while(datamap->map.map[i])
	{
		if(datamap->map.map[i] == '1')
			datamap->map.wall += 1;
		if(datamap->map.map[i] == 'E')
			datamap->map.exit += 1;
		if(datamap->map.map[i] == 'P')
		{
			datamap->map.player += 1;
			datamap->map.player_pos = i;
		}
		if(datamap->map.map[i] == 'C')
			datamap->map.consomable += 1;
		i++;
	}
}

int   parsingcorrect(t_data *datamap)
{
	int     i;

	unitializeandparse(datamap);
	i = 0;
	while(datamap->map.map[i] && datamap->map.map != NULL)
	{
		if (datamap->map.map[i] != '1' && datamap->map.map[i] != '0' && datamap->map.map[i] != 'E' && datamap->map.map[i] != 'P' && datamap->map.map[i] != 'C' && datamap->map.map[i] != '\n')
			return (0);
		i++;
	}
	if (datamap->map.exit != 1 || datamap->map.player != 1 || datamap->map.consomable < 1)
		return(0);
}