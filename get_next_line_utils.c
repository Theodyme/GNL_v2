#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cc;

	if (!b)
		return (NULL);
	cc = (unsigned char *)b;
	while (len--)
		cc[len] = (unsigned char)c;
	b = (void *)cc;
	return (b);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	if (src == NULL || dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}


size_t	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str && str[l] != '\0')
		l++;
	return (l);
}

void	*ft_calloc(size_t count, size_t size)
{
	int	*tab;

	tab = (void *)malloc(size * count);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, size * count);
	return (tab);
}

char	*ft_strdup(const char *src)
{
	int		l;
	char	*str;

	if (src == NULL)
		return (NULL);
	l = ft_strlen((char *)src);
	str = (char *)ft_calloc(sizeof(*str), (l + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}