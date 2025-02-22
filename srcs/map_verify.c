/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:42:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/11 17:00:27 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	create_map(t_list **lst, char *content)
// {
// 	t_list	*new_node;

// 	new_node = ft_lstnew(content);
// 	if (!new_node)
// 		return ;
// 	ft_lstadd_back(lst, new_node);
// }

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

int	verif_filetype(char *file)
{
	int		len;
	int		i;
	char	*type;

	type = ".ber";
	len = ft_strlen(file);
	i = 1;
	while (i < 5)
	{
		if (file[len - i] != type[4 - i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_error_file(void)
{
  ft_printf("Error\n");
  return (1);
}

void	fr_free_map(t_verif_path *path)
{
  int i;

  i = 0;
  while (path->map[i])
  {
    free(path->map[i]);
    i++;
  }
  free(path->map);
}

int	map_verify(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	char	*str_map;
	int		code;
  t_verif_path  verif_path = {NULL, 0, 0, 0, 0};

	code = 0;
  if (!map_file)
    return (ft_error_file());
	if (verif_filetype(map_file))
		return (ft_error_file());
	str_map = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ft_error_file());
		// root_destroy(root, map_file, errno);
	while ((line = get_next_line(fd)) != NULL)
  {
		str_map = create_map(str_map, line);
    free(line);
  }
	game->map = ft_split(str_map, '\n');
  verif_path.map = ft_split(str_map, '\n');
	free(str_map);


	if (verif_map_struct(game, &verif_path))
    code = 1;
  fr_free_map(&verif_path);

	// if (verif_mapsize(game))
	// 	code = 1;
	// if (verif_map_elem(game))
	// 	code = 1;

	close(fd);
	return (code);
}
