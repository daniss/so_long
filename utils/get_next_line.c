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
	if (!firstpart)
		return (NULL);
	while (i != len + 1)
	{
		firstpart[i] = str[i];
		i++;
	}
	firstpart[i] = 0;
	return (firstpart);
}

char	*ft_secpart(char *str, int j)
{
	int		i;
	int		len;
	char	*ret;

	len = 0;
	i = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	ret = malloc(sizeof(char) * (ft_strlengnl(str) - len + 1));
	if (!ret)
		return (NULL);
	while (str && str[len])
		ret[i++] = str[++len];
	ret[i] = 0;
	if ((j == 0 && ret[j] == '\0') || ret[0] == '\0')
	{
		free(ret);
		ret = NULL;
	}
	free(str);
	return (ret);
}

char	*reading(int *i, char *str, int fd)
{
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0 || !buff)
	{
		free(buff);
		return (NULL);
	}
	while (*i > 0)
	{
		*i = read(fd, buff, BUFFER_SIZE);
		if (*i == 0 && !str)
		{
			free(buff);
			return (NULL);
		}
		str = ft_strjoingnl(str, buff, *i);
		if (ft_strrchrgnl(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*ret;
	char		*temp;
	int			i;

	i = 1;
	str = reading(&i, str, fd);
	if (str == NULL)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	ret = ft_firstpart(str, &temp);
	str = ft_secpart(temp, i);
	return (ret);
}
