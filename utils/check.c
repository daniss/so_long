/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:05 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/19 11:45:05 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int checkcolonwall(t_data *mapdata)
{
	int i;

	i = 0;
	while(mapdata->map.map[i] != '\0' && mapdata->map.map[i+1] != '\0')
	{
		if(mapdata->map.map[i] != '1' && mapdata->map.map[i+1] != '\0')
			return(0);
		if(mapdata->map.map[i+1] == '\n')
			i += 2;
		else
			i += mapdata->map.colon - 1 ;
	}
	return(1);
}

int checklignwall(t_data *mapdata)
{
	int i;
	int nblign;

	i = 0;
	nblign = 1;
	while(mapdata->map.map[i] != '\n') // check first wall lign
		if (mapdata->map.map[i++] != '1')
			return(0);
	while(nblign != mapdata->map.lign) // find first cara of the last lign wall
		if(mapdata->map.map[i++] == '\n')
			nblign++;
	while(mapdata->map.map[i] != '\n' && mapdata->map.map[i] != '\0') // check last wall lign
	{
		if (mapdata->map.map[i] != '1')
			return(0);
		i++;
	}
	return(1);
}

void check(int argc, char **argv, t_data *mapdata)
{
	int fd;

	if (argc != 2)
	{
		free(mapdata);
		error("Invalid number of arguments! \n");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(mapdata);
		error("File error!\n");
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		free(mapdata);
		error("File type error, please use .ber file !\n");
	}
	get_map(fd, mapdata);
	if (checklignwall(mapdata) == 0 || checkcolonwall(mapdata) == 0 || parsingcorrect(mapdata) == 0 || mapdata->map.colon == mapdata->map.lign)
	{
		free(mapdata->map.map);
		free(mapdata);
		error("Error with the map\n");
	}
	//checkroute(mapdata);
}