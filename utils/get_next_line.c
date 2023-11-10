/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:15:41 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/07 14:15:41 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*ft_firstpart(char *str, char **temp)
{
	int		len;
	int		i;
	char	*firstpart;

	len = 0;
	i = 0;
	*temp = str;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		firstpart = malloc(sizeof(char) * (len + 2));
	else
		firstpart = malloc(sizeof(firstpart) * (len + 1));
	while (i != len + 1)
	{
		firstpart[i] = str[i];
		i++;
	}
	firstpart[i] = 0;
	return (firstpart);
}

static char	*ft_secpart(char *str, int j)
{
	int		i;
	int		len;
	char	*ret;

	len = 0;
	i = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	ret = malloc(sizeof(char) * (ft_strlen(str) - len + 1));
	if (!ret)
		return (NULL);
	while (str && str[len])
		ret[i++] = str[++len];
	ret[i] = 0;
	if (j == 0 && ret[j] == '\0')
	{
		free(ret);
		ret = NULL;
	}
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*ren;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = 0;
		str = ft_strjoin(str, buff);
		if (ft_strrchr(str, '\n'))
			break ;
	}
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	ren = ft_firstpart(str, &temp);
	str = ft_secpart(temp, i);
	return (ren);
}

/*
int main()
{
	int fd;
	int	i = 0;
	char *test;
	fd = open("map.ber", O_RDONLY);
	test = get_next_line(fd);
	printf("%s", test);
	free(test);
	while(i != 14)
	{
		test = get_next_line(fd);
		if(test == NULL)
			break;
		printf("%s", test);
		free(test);
		i++;
	}
}*/