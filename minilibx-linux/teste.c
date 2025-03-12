#include "./libft/libft.h"
#include "stdio.h"
#include <fcntl.h>
#include <stdio.h>

char	*create_map(char *map, char *line)
{
	char	*temp;

  temp = NULL;
	if (map == NULL)
    map = ft_strjoin("", line);
	else
	{
    temp = map;
		map = ft_strjoin(map, line);
    free(temp);
	}
  // printf("--> %s", map);
  // printf("\n|map--> %s|\n", temp);
	return (map);
}

int main(int argc, char **argv)
{
	int		file_descriptor;
	char	*line;
	int		n;

	n = 1;
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Error opening file!\n", 20);
		return (1);
	}
  char	*str_map;
  // char  *map;
  // map = "oi.";
  str_map = NULL;
	while ((line = get_next_line(file_descriptor)) != NULL)
	{
    // printf("%s", line);

    str_map = create_map(str_map, line);
    printf("--> %s", str_map);
    printf("\n");
    free(line);
	}
  // printf("\n|map--> %s|\n", temp);

	free(str_map);

	close(file_descriptor);
	return (0);
}
