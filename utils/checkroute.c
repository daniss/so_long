#include "../includes/so_long.h"
#include <stdbool.h>
// Function to check if there is an available route
bool isRouteAvailable(char map[3][6], int row, int col) {
    // Check if the current position is within the map
    if (row < 0 || row >= row || col < 0 || col >= col) {
        return false;
    }
    printf("test");
    // Check if the current cell is the endpoint 'E'
    if (map[row][col] == 'E') {
        return true;
    }

    // Mark the current cell as visited
    map[row][col] = 'v';

    // Check neighboring cells (up, down, left, right)
    if (map[row][col] != '1' &&
        isRouteAvailable(map, row - 1, col) ||
        isRouteAvailable(map, row + 1, col) ||
        isRouteAvailable(map, row, col - 1) ||
        isRouteAvailable(map, row, col + 1)) {
        return true;
    }

    return false;
}

void findStart(char map[3][6], int *startRow, int *startCol) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (map[i][j] == 'P') {
                *startRow = i;
                *startCol = j;
                return;
            }
        }
    }
}

void    convertstringto2d(t_data *mapdata, char **map)
{
    int i;
    int j;
    int k;
    i = 0;
    k = 0;
    j = 0;
    while(mapdata->map.map[i] != '\0' && j < mapdata->map.lign)
    {
        if(mapdata->map.map[i] == '\n')
        {  
            i++;
            j++;
            k = 0;
        }
        else
        {
            map[j][k] = mapdata->map.map[i];
            k++;
            i++;
        }
    }
}

int checkroute(t_data *mapdata)
{
    char map[mapdata->map.lign][mapdata->map.colon-1];
    int i;
    int j;
    int k;
    i = 0;
    k = 0;
    j = 0;
    while(mapdata->map.map[i] != '\0' && j < mapdata->map.lign)
    {
        if(mapdata->map.map[i] == '\n')
        {  
            i++;
            j++;
            k = 0;
        }
        else
        {
            map[j][k] = mapdata->map.map[i];
            k++;
            i++;
        }
    }
    int startRow, startCol;
    findStart(map, &startRow, &startCol);
    printf("\n%d\n", startCol);
    printf("%d", isRouteAvailable(map, startRow, startCol));
}