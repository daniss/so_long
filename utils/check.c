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
// check if there is a wall around the map
int	checkcolonwall(t_data *mapdata)
{
	int	i;

	i = 0;
	while (mapdata->map.map[i] != '\0' && mapdata->map.map[i + 1] != '\0')
	{
		if (mapdata->map.map[i] != '1' && mapdata->map.map[i + 1] != '\0')
			return (0);
		if (mapdata->map.map[i + 1] == '\n')
			i += 2;
		else
			i += mapdata->map.colon - 1 ;
	}
	return (1);
}

// check if there is a wall around the map
int	checklignwall(t_data *mapdata)
{
	int	i;
	int	nblign;

	i = 0;
	nblign = 1;
	while (mapdata->map.map[i] != '\n')
		if (mapdata->map.map[i++] != '1')
			return (0);
	while (nblign != mapdata->map.lign)
		if (mapdata->map.map[i++] == '\n')
			nblign++;
	while (mapdata->map.map[i] != '\n' && mapdata->map.map[i] != '\0')
	{
		if (mapdata->map.map[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// global check regroup all the checking
// check if the file type, exist or error with read or empty file
// checkconso, check if the conso is not surounded by wall
void	check(int argc, char **argv, t_data *mapdata)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
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
	if (!checklignwall(mapdata)
		|| !checkcolonwall(mapdata)
		|| !parsingcorrect(mapdata) || mapdata->map.colon == mapdata->map.lign
		|| !check_path(argv[1], mapdata->map.lign)
		|| !check_conso(argv[1], mapdata->map.lign, mapdata->map.consomable))
	{
		free(mapdata->map.map);
		free(mapdata);
		error("Error with the map\n");
	}
}
