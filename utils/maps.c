/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:31 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/19 11:45:31 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map(int fd, t_data *mapdata)
{
	char	*str;
	int		i;

	i = 0;
	mapdata->map.map = NULL;
	str = get_next_line(fd);
	if (!str)
		return (0);
	while (str[mapdata->map.colon] && str[mapdata->map.colon] != '\n')
		mapdata->map.colon++;
	while (str != NULL)
	{
		mapdata->map.map = ft_strjoin(mapdata->map.map, str);
		free(str);
		str = get_next_line(fd);
		while (str != NULL && str[i] && str[i] != '\n')
			i++;
		if (str != NULL && mapdata->map.colon != i)
			error("Error with the map\n");
		mapdata->map.lign++;
		i = 0;
	}
	free(str);
	return (1);
}
