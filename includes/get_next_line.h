#ifndef GNL_H
# define GNL_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <stdint.h>
int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char	*ft_firstpart(char *str);
char	*ft_secpart(char *str);


#endif