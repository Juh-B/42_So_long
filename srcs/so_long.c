/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:46 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/10 18:14:04 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
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

int	map_verif(char *map_file, char	**map)
{
	int		fd;
	char	*line;
	char	*str_map;
	// char	*file;
	// char	buf[1024];
	// int		ret;

	printf("its me");
	str_map = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (1);
		// root_destroy(root, map_file, errno);

	while ((line = get_next_line(fd)) != NULL)
		create_map(str_map, line);
	map = ft_split(str_map, '\n');
	return (0);
}

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	char	**map_compl;

	printf("oi");
	map_compl = NULL;
	if (argc == 2)
	{
		map_verif(argv[1], map_compl);
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		// mlx_loop(mlx);
	}
	int i = 0;
	while (map_compl[i])
	{
		printf("%s\n", map_compl[i]);
		i++;
	}
	return (0);
}
