/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:06:59 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/28 21:54:23 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_is_rect(char *path)
{
	char	*line;
	size_t	len;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(MAP_RD_ERROR);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != len)
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

static int	check_has_edges(char **map, int w, int h)
{
	int	row;
	int	coll;

	row = 0;
	coll = 0;
	while (map[0][coll])
		if (map[0][coll++] != '1')
			return (0);
	coll = 0;
	while (map[h - 1][coll])
		if (map[h - 1][coll++] != '1')
			return (0);
	while (map[row])
		if (map[row++][0] != '1')
			return (0);
	row = 0;
	while (map[row])
		if (map[row++][w - 1] != '1')
			return (0);
	return (1);
}

static void	check_chars(t_game *game, char **map)
{
	int	row;
	int	coll;

	row = 0;
	coll = 0;
	while (map[row])
	{
		coll = 0;
		while (map[row][coll])
		{
			if (map[row][coll] == 'E')
				game->map.count_exit++;
			if (map[row][coll] == 'C')
				game->map.count_col++;
			if (map[row][coll] == 'P')
				game->map.count_pla++;
			coll++;
		}
		row++;
	}
}

void	check_map(t_game *game)
{
	if (!check_is_rect(game->map.path))
		error_msg(MAP_ERROR);
	if (!check_has_edges(game->map.map, game->map.width, game->map.height))
		error_msg(MAP_ERROR);
	check_chars(game, game->map.map);
	if (!game->map.count_exit || !game->map.count_col || !game->map.count_pla)
		error_msg(MAP_ERROR);
	if (game->map.count_pla > 1)
		error_msg(PLAYER_ERROR);
}

void	check_all(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	fd = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(path, O_RDONLY);
		if (path[len - 4] != '.' || path[len - 3] != 'b'
			|| path[len - 2] != 'e' || path[len - 1] != 'r' || fd < 0)
			error_msg(FILE_ERROR);
	}
	close(fd);
}
