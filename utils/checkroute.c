/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkroute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:46:16 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/26 22:36:50 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

static int check_valid_path(t_maparray *copy, int x, int y, char c)
{
	if (copy->maparray[y][x] == '1')
		return 0;
	if (copy->maparray[y][x] == c)
		return 1;
	copy->maparray[y][x] = '1';
	if (check_valid_path(copy, x, y + 1, c))
		return 1;
	if (check_valid_path(copy, x, y - 1, c))
		return 1;
	if (check_valid_path(copy, x + 1, y, c))
		return 1;
	if (check_valid_path(copy, x - 1, y, c))
		return 1;
	return 0;
}

static void	find_player(t_maparray *copy)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(copy->maparray[i])
	{
		while(copy->maparray[i][j])
		{
			if(copy->maparray[i][j] == 'P')
			{
				copy->x = j;
				copy->y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	free_array(t_maparray *copy, int lign)
{
	int i;

	i = 0;
	while(i < lign)
	{
		free(copy->maparray[i]);
		i++;
	}
	free(copy->maparray);
}

int check_path(char *argv, int lign)
{
	t_maparray	copy;
	char		*str;
	int     	fd;
	int	i = 0;

	fd = open(argv, O_RDONLY);
	copy.maparray = malloc(sizeof(char **) * lign);
	if (copy.maparray == NULL)
		return 1;
	while(1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		copy.maparray[i++] = str;
	}
	find_player(&copy);
	if (check_valid_path(&copy, copy.x, copy.y, 'E') == 1)
	{
		free_array(&copy, lign);
		return (1);
	}
	free_array(&copy, lign);
	return (0);
}
