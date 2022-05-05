/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:54:49 by rade-sar          #+#    #+#             */
/*   Updated: 2022/04/28 22:08:35 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* INCLUDES */

# include "./libft/library/libft.h"
# include <mlx.h>

/* DEFINES */

# define A 97
# define D 100
# define S 115
# define W 119
# define TOP 65362
# define BOT 65364
# define LEFT 65361
# define RIGHT 65363
# define PIXEL_SIZE 50
# define TITLE "GAME"

/* ERRORS */

# define FILE_ERROR "Argument is not a .ber file.\n"
# define MAP_RD_ERROR "Could not open map.\n"
# define MAP_SHP_ERROR "Map has not a valid shape.\n"
# define MAP_ERROR "Map must have edges (walls).\n"
# define CHAR_ERROR "There should be at least 1 item, 1 player and 1 exit.\n"
# define PLAYER_ERROR "There should only be one player.\n"
# define MLX_ERROR "Could not open mlx.\n"

/* IMAGES */

# define WALL "./images/wall.xpm"
# define EXIT "./images/exit.xpm"
# define BACK_GRD "./images/ground.xpm"
# define PLAYER "./images/player.xpm"
# define COLL "./images/coll.xpm"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

/* STRUCTS */

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_map
{
	int			fd;
	char		*path;
	char		**map;
	int			height;
	int			width;
	int			count_col;
	int			count_exit;
	int			count_pla;
	int			collected;
	int			can_exit;
	t_player	player;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*back_ground;
	void	*player;
	void	*collectable;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		steps;
	t_map	map;
	t_img	img;
}	t_game;

/* INIT FUNCTIONS */

void		init_game(char *path, t_game *game);
void		init_window(t_game *game);
void		init_images(t_game *game);
void		delete_images(t_game game);

/* CHECK FUNCTIONS */

int			error_msg(char *str);
void		check_all(char *path);
void		check_map(t_game *game);

/* FREE MAP */

void		free_map(char **map);

#endif
