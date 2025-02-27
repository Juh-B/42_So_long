/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:42:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/27 15:37:06 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_error_file(void)
{
	ft_printf("Error\n");
	return (1);
}

static int	verif_filetype(char *file)
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

void	ft_free_map(t_verif_path *path)
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

static char	*get_map(char *map, char *line)
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
	return (map);
}


int	read_map_file(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	char	*str_map;
	int		code;
	t_verif_path  verif_path = {NULL, 0, 0, 0, 0};

	code = 0;
	str_map = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		str_map = get_map(str_map, line);
		free(line);
	}
	game->map = ft_split(str_map, '\n');
	verif_path.map = ft_split(str_map, '\n');
	free(str_map);
	if (verif_map_struct(game, &verif_path))
		code = 1;
	ft_free_map(&verif_path);
	close(fd);
	return (code);
}

int	verif_map(char *map_file, t_game *game)
{
	int		code;

	code = 0;
	if (!map_file)
		return (ft_error_file());
	if (verif_filetype(map_file))
		return (ft_error_file());
	code = read_map_file(map_file, game);
	if (code == -1)
		return (ft_error_file());
	return (code);
}

// int	verif_map(char *map_file, t_game *game)
// {
// 	int		fd;
// 	char	*line;
// 	char	*str_map;
// 	int		code;
//   t_verif_path  verif_path = {NULL, 0, 0, 0, 0};

// 	code = 0;
//   if (!map_file)
//   return (ft_error_file());
// 	if (verif_filetype(map_file))
//   return (ft_error_file());

// 	str_map = NULL;
// 	fd = open(map_file, O_RDONLY);
// 	if (fd == -1)
// 		return (ft_error_file());
// 	while ((line = get_next_line(fd)) != NULL)
//   {
// 		str_map = get_map(str_map, line);
//     free(line);
//   }
// 	game->map = ft_split(str_map, '\n');
//   verif_path.map = ft_split(str_map, '\n');
// 	free(str_map);
// 	if (verif_map_struct(game, &verif_path))
//     code = 1;
//   ft_free_map(&verif_path);
// 	close(fd);
// 	return (code);
// }