#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct  s_buffer
{
    char                chunk[BUFFER_SIZE + 1];
    struct s_buffer     *next;
}               t_buffer;

t_buffer    *lst_last(t_buffer *buffer);
void                lst_add(t_buffer **buffer);
int                 read_in_buffer(t_buffer **buffer, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
char *get_next_line(int fd);

#endif