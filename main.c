#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int     main(int ac, char **av)
{
    char    *filename;
    char    *line;

    if (ac == 1 || ac > 2)
        return 0;
    filename = ft_strdup(av[1]);
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Unable to open file");
        return (EXIT_FAILURE);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (EXIT_SUCCESS);
}