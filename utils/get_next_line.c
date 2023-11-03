#include "../includes/get_next_line.h"

char	*ft_firstpart(char *str)
{
	int	i;
	char	*ren;

	i = 0;
	if(!str[i])
		return (NULL);
	while(str[i] != '\0')
		i++;
	ren = malloc(sizeof(char) * (i + 2));
	if(!ren)
		return (NULL);
	i = 0;
	while(str[i] != '\0')
	{
		ren[i] = str[i];
		i++;
	}
	ren[i] = 0;
	return (ren);
}

char	*ft_secpart(char *str)
{
	int		i;
	char	*ren;
	int		len;
	int		pos;

	pos = 0;
	len = 0;
	i = 0;
	if(str == 0)
		return (NULL);
	while(str[i] != '\0')
		i++;
	pos = i;
	while(str && str[i] != '\0' && str[i-1] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	ren = malloc(sizeof(char) * (len + 1));
	if(!ren)
		return (NULL);
	while(str[pos]!= '\0')
	{
		ren[i] = str[pos];
		i++;
		pos++;
	}
	ren[i] = 0;
	return (ren);
}

char    *get_next_line(int fd)
{
	static char *str = NULL;
	char	*ren;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;
	size_t	i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while(i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = 0;
		temp = str;
		str = ft_strjoin(temp, buff);
		if(strchr(str, '\n'))
			break ;
	}
	ren = ft_firstpart(str);
	temp = str;
	str = ft_secpart(temp);
	if(i == 0)
	{
		free(str);
		str = NULL;
	}
	free(temp);
	return(ren);
}