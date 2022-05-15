/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:05:51 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/28 21:56:58 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

static void	init_map(t_game *game)
{
	char	*line;
	int		row;
	int		coll;
	int		i;

	line = get_next_line(game->map.fd);
	row = 0;
	coll = 0;
	i = 0;
	while (line)
	{
		game->map.map[row] = ft_calloc(game->map.width + 1, sizeof(char));
		if (!(game->map.map[row]))
			return (free_map(game->map.map));
		i = 0;
		coll = 0;
		while (line[i] && line[i] != '\n')
			game->map.map[row][coll++] = line[i++];
		game->map.map[row++][coll] = '\0';
		free(line);
		line = get_next_line(game->map.fd);
	}
	game->map.map[row] = NULL;
}

static int	get_height(char *path, t_game *game)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	count = 0;
	if (fd < 0)
		error_msg(MAP_RD_ERROR);
	line = get_next_line(fd);
	game->map.width = ft_strlen(line) - 1;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	init_game(char *path, t_game *game)
{
	init_game_stats(game);
	game->map.fd = open(path, O_RDONLY);
	if (game->map.fd < 0)
		error_msg(MAP_RD_ERROR);
	game->map.height = get_height(path, game);
	game->map.map = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!(game->map.map))
		return ;
	init_map(game);
	game->width = game->map.width * PIXEL_SIZE;
	game->height = game->map.height * PIXEL_SIZE + 25;
	game->img.width = PIXEL_SIZE;
	close(game->map.fd);
	init_game_window(game);
}
