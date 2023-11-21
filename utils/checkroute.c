/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkroute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:46:16 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/19 15:09:22 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

typedef struct {
    int row;
    int col;
} Cell;

int	checkconso(t_data *mapdata)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(mapdata->map.map[i])
	{
		if(mapdata->map.map[i] == 'C')
		{
			if(mapdata->map.map[i + 1] == '1' && mapdata->map.map[i - 1] == '1'
			&& mapdata->map.map[i + mapdata->map.colon + 1] == '1' && mapdata->map.map[i - mapdata->map.colon - 1] == '1')
				return(0);
		}
		i++;
	}
	return(1);
}

bool isRouteAvailable(char map[6][19], int startRow, int startCol) {
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    Cell *stack = (Cell *)malloc(6 * 19 * sizeof(Cell));
    int top = 0;

    stack[top++] = (Cell){startRow, startCol};

    while (top > 0) {
        Cell currentCell = stack[--top];
        int row = currentCell.row;
        int col = currentCell.col;

        if (map[row][col] == 'E') {
            free(stack);
            return true;
        }

        map[row][col] = 'v';

        int i = 0;
        while (i < 4) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < 6 && newCol >= 0 && newCol < 19 &&
                map[newRow][newCol] != '1' && map[newRow][newCol] != 'v') {
                stack[top++] = (Cell){newRow, newCol};
            }

            i++;
        }
    }

    free(stack);
    return false;
}

void findStart(char map[6][19], int *startRow, int *startCol) {
    int i = 0, j = 0;
    while (i < 6) {
        j = 0;
        while (j < 19) {
            if (map[i][j] == 'P') {
                *startRow = i;
                *startCol = j;
                return;
            }
            j++;
        }
        i++;
    }
}

char	**maptodd(t_data *mapdata)
{
	char	**map;
	int		i;

	i = 0;
	**map = (char **)malloc(mapdata->map.lign * sizeof(char *));
	if(!map)
		return(NULL);
	while (i < mapdata->map.lign)
	{
		map[i] = (char *)malloc(mapdata->map.colon * sizeof(char));
		if(!map[i])
			return(NULL);
		i++;
	}
	return(map);
}

void	checkroute(t_data *mapdata)
{
	if(checkconso(mapdata) == 0)
	{
		free(mapdata->map.map);
		free(mapdata);
		error("Map not valid\n");
	}

    /*char map[6][19] = {
        "1111111111111111111",
        "1E1111111111111C111",
        "1010100100000101001",
        "1010010101010001001",
        "1P1111111C111111111",
        "1111111111111111111"
    };

    int startRow, startCol;
    findStart(map, &startRow, &startCol);

    bool result = isRouteAvailable(map, startRow, startCol);

    if (result) {
        printf("There is an available route from P to E.\n");
    } else {
        printf("There is no available route from P to E.\n");
    }*/

}
