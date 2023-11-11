#include "../includes/so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] && i + j < len)
				j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	b;
	char	*ren;

	i = 0;
	b = 0;
	if (!s2)
		return (NULL);
	ren = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!ren)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		ren[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
		ren[i++] = s2[b++];
	ren[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (ren);
}
