#include "get_next_line.h"
#include <string.h>  // Include for memcpy and memmove
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	if (s == NULL)
		return (NULL);
	while (s[++i] != (char)c)
		if (s[i] == '\0')
			return (NULL);
	return ((char *)&(s[i]));
}

t_buffer *lst_last(t_buffer *buffer)
{
    while (buffer && buffer->next)
        buffer = buffer->next;
    return (buffer);
}

void lst_add(t_buffer **buffer)
{
    t_buffer *new;

    new = malloc(sizeof(t_buffer));
    new->next = NULL;
    if (!(*buffer))
        *buffer = new;
    else
        (lst_last(*buffer))->next = new;
    return;
}

int read_in_buffer(t_buffer **buffer, int fd)
{
    int i;

    i = 0;
    lst_add(buffer);
    i = read(fd, lst_last((*buffer))->chunk, BUFFER_SIZE);
    printf("i = %d\n", i);
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*ref;
	int		l1;
	int		l2;

	if (!s1 || !s2 || (!s1 && !s2))
		return (NULL);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	s3 = ft_calloc(sizeof(char), (l1 + l2 + 1));
	if (!s3)
		return (NULL);
	ref = s3;
	while (l1-- > 0)
		*s3++ = *s1++;
	while (l2-- > 0)
		*s3++ = *s2++;
	*s3 = '\0';
	return (ref);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pdst;

	if (!dst && !src)
		return (NULL);
	pdst = (char *)dst;
	while (n-- > 0)
		*pdst++ = *(const char *)src++;
	return (dst);
}

void buffer_cleaner(t_buffer **buffer, char **line, char *idx)
{
    ft_strjoin(*line, (((*buffer)->chunk) - ft_strlen(idx)));
    ft_memcpy((*buffer)->chunk, (*buffer)->chunk + ft_strlen(idx) + 1, (BUFFER_SIZE - ft_strlen(idx)));
}

void    get_line(t_buffer **buffer, char **line)
{
    char        *idx;
    t_buffer    *tmp;

    idx = NULL;
    tmp = *buffer;
    while (tmp)
    {
        idx = ft_strchr(tmp->chunk, '\n');
        if (idx != NULL)
            buffer_cleaner(buffer, line, idx);
        else
        {
            *line = ft_strjoin(*line, tmp->chunk);
            *buffer = tmp->next;
            free(tmp->chunk);
            tmp = *buffer;
        }
    }
}

char *get_next_line(int fd)
{
    static t_buffer *current_read;
    int             read;
    char            *line;

    if (fd < 0)
        return (NULL);
    read = 1;
    line = NULL;
    while (read != 0 && read != -1)
    {
        read = read_in_buffer(&current_read, fd);
        if (read != 0 && read != -1)
            get_line(&current_read, &line);
    }
    printf("pouet");
    return (line);
}

