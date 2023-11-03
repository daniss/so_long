#include "../includes/get_next_line.h"

int ft_strlen(char *s)
{
	size_t  i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t     i;
	size_t     b;
	char    *ren;

	i = 0;
	b = 0;
	if(!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	ren = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if(s1)
	{
		while(s1[i] != '\0')
		{
			ren[i] = s1[i];
			i++;
		}
	}
	while(s2[b] != '\0')
	{
		ren[i] = s2[b];
		i++;
		b++;
	}
	ren[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return(ren);
}