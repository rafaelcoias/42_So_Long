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
	if (len < 5)
		error_msg(SMALL_MAP_ERROR);
	while (line)
	{
		if (ft_strlen(line) != len)
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

static void	confirm_chars(t_game *game, char *line, int row, int coll)
{
	if ((row == 0 || row == game->map.height - 1
			|| coll == 0 || coll == game->map.width - 1))
		if (line[coll] != '1')
			error_msg(MAP_ERROR);
	if (line[coll] == 'E')
		game->map.count_exit++;
	else if (line[coll] == 'C')
		game->map.count_col++;
	else if (line[coll] == 'P')
		game->map.count_pla++;
	else if (line[coll] == '0')
		game->map.count_ground++;
}

static void	check_chars(t_game *game, char *path)
{
	int		row;
	int		coll;
	char	*line;
	int		fd;

	row = 0;
	coll = -1;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(MAP_RD_ERROR);
	line = get_next_line(fd);
	while (line)
	{
		coll = -1;
		while (line[++coll + 1])
			confirm_chars(game, line, row, coll);
		row++;
		free(line);
		line = get_next_line(fd);
	}	
}

void	check_map(t_game *game)
{
	game->map.count_exit = 0;
	game->map.count_col = 0;
	game->map.count_pla = 0;
	if (!check_is_rect(game->map.path))
		error_msg(MAP_SHP_ERROR);
	check_chars(game, game->map.path);
	if (!game->map.count_exit || !game->map.count_col || !game->map.count_pla)
		error_msg(CHAR_ERROR);
	if (game->map.count_pla > 1)
		error_msg(PLAYER_ERROR);
}

void	check_ber(char *path)
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
