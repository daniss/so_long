#include "../includes/so_long.h"

int checkcolonwall(char *map, int colon)
{
	int i;

	i = 0;
	while(map[i] != '\0' && map[i+1] != '\0')
	{
		if(map[i] != '1' && map[i+1] != '\0')
			return(0);
		if(map[i+1] == '\n')
			i += 2;
		else
			i += colon - 1 ;
	}
	return(1);
}

int checklignwall(char *map, int colon, int lign)
{
	int i;
	int nblign;

	i = 0;
	nblign = 1;
	while(map[i] != '\n') // check first wall lign
		if (map[i++] != '1')
			return(0);
	while(nblign != lign) // find first cara of the last lign wall
		if(map[i++] == '\n')
			nblign++;
	while(map[i] != '\n' && map[i] != '\0') // check last wall lign
	{
		if (map[i] != '1')
			return(0);
		i++;
	}
	return(1);
}

int check(int argc, char **argv)
{
	int fd;
	int lign;
	int colon;
	t_map map;

	if (argc != 2)
		error("Invalid number of arguments! \n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("File error!\n");
	if(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error("File type error, please use .ber file !\n");
	map.map = get_map(fd, &colon, &lign); // get map, colon and lign
	if (checklignwall(map.map, colon, lign) == 0 || checkcolonwall(map.map, colon) == 0 || parsingcorrect(&map) == 0 || colon == lign)
		error("Error with the map\n");
	map_unitialize(colon, lign, map);
	return (1);
}