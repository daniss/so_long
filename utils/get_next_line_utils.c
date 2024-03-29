/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcindrak <dcindrak@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:15:53 by dcindrak          #+#    #+#             */
/*   Updated: 2023/11/07 14:15:53 by dcindrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strrchrgnl(const char *s, int c)
{
	int	i;
	int	pos;

	pos = -1;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			pos = i;
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	if (pos > -1)
		return ((char *)(s + pos));
	return (NULL);
}

int	ft_strlengnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoingnl(char *s1, char *s2, int j)
{
	size_t	i;
	size_t	b;
	char	*ren;

	i = 0;
	b = 0;
	s2[j] = 0;
	if (!s2)
		return (NULL);
	ren = malloc(sizeof(char) * ((ft_strlengnl(s1) + ft_strlengnl(s2)) + 1));
	if (!ren)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		ren[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
		ren[i++] = s2[b++];
	ren[ft_strlengnl(s1) + ft_strlengnl(s2)] = '\0';
	free(s1);
	return (ren);
}
