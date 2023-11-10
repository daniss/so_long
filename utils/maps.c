#include "../includes/so_long.h"

char *get_map(int fd, int *count, int *lign)
{
	char	*map;
	char	*str;
	int		i;

	i = 0;
	*count = 0;
	*lign = 0;
	map = NULL;
	str = get_next_line(fd);
	while (str[*count] && str[*count] != '\n')
		(*count)++;
	while (str != NULL)
	{
		map = ft_strjoin(map, str);
		free(str);
		str = get_next_line(fd);
		while (str != NULL && str[i] && str[i] != '\n')
			i++;
		if (str != NULL && *count != i)
		{
			error("Error with the map\n");
		}
		(*lign)++;
		i = 0;
	}
	free(str);
	return (map);
}