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

# include "./libft/libft.h"
# include "./images/images.h"


/* DEFINES */

# define A 97
# define D 100
# define S 115
# define W 119
# define TOP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESCAPE 27
# define ENTER "a"
# define PIXEL_SIZE 50
# define TITLE "GAME"
# define MAP_TEST "../include/maps/mapa.ber"

/* ERRORS */

# define FILE_ERROR "Argument is not a .ber file.\n"
# define MAP_RD_ERROR "Could not open map.\n"
# define MAP_SHP_ERROR "Map has not a valid shape.\n"
# define MAP_ERROR "Map must have edges (walls).\n"
# define SMALL_MAP_ERROR "Map is too small.\n"
# define CHAR_ERROR "There should be at least 1 item, 1 player and 1 exit.\n"
# define PLAYER_ERROR "There should only be one player.\n"
# define MLX_ERROR "Could not open mlx.\n"
# define WIN_ERROR "Could not find window.\n"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

/* STRUCTS */

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
	int			count_ground;
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
	void	*player_w_coll;
	void	*collectable;
	void	*block;
	void	*transport;
	void	*water;
	void	*line;
	void	*semi_line;
	void	*mov;
	void	*es;
	void	*win;
	void	*lose;
	void	*nbr;
	void	*menu_test;
	void	*menu_play;
	void	*menu_exit;
}	t_img;

typedef struct s_menu
{
	int		test;
	int		play;
	int		exit;
}	t_menu;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		p_i;
	int		p_j;
	int		has_coll;
	int		count_moves;
	t_menu	menu;
	t_map	map;
	t_img	img;
}	t_game;

/* INIT FUNCTIONS */

void		init_game(char *path, t_game *game);
void		init_window(t_game *game);
void		init_images(t_game *game);
void		render_images(t_game *game);
void		delete_images(t_game game);

/* CHECK FUNCTIONS */

int			error_msg(char *str);
void		check_ber(char *path);
void		check_map(t_game *game);

/* GAME FUNCTIONS */

void    	do_game(t_game game);
void		handle_keypress(int key, t_game *game);
void		move_player(t_game *game, char move);
void		end_game(t_game *game, int win);

/* FREE MAP */

void		free_map(char **map);

#endif
