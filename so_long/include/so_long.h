/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:54:49 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/12 14:28:52 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* INCLUDES */

# include "./libft/libft.h"
# include "./images/images.h"
# include <mlx.h>

/* DEFINES */

# define A 0
# define D 2
# define S 1
# define W 13
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESCAPE 53
# define ENTER 36
# define PIXEL_SIZE 50
# define MAP_TEST "include/maps/tutorial.ber"

/* ERRORS */

# define FILE_ERROR "Argument is not a .ber file.\n"
# define DIR_ERROR "Argument is a directory, must be a .ber file\n"
# define FILE_NAME "The .ber file must have a name.\n"
# define PATH_ERROR "Could not find file path / path does not exists.\n"
# define MAP_RD_ERROR "Could not open map.\n"
# define MAP_SHP_ERROR "Map has not a valid shape.\n"
# define EDGES_ERROR "Map must have edges (walls).\n"
# define CHAR_ERROR "Map must have at least 1 item, 1 exit & only 1 player.\n"
# define UNKNOWN_CHAR "Unknown char in map.\n"
# define PLAYER_ERROR "There should only be one player.\n"
# define MLX_ERROR "Could not open mlx.\n"
# define WIN_ERROR "Could not find window.\n"

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

typedef struct s_menu
{
	void	*mlx;
	void	*window;
	int		width;
	int		in_menu;
	int		in_game;
	int		in_end;
	int		test;
	int		play;
	int		exit;
}	t_menu;

typedef struct s_end
{
	void	*mlx;
	void	*window;
	int		width;
	int		win;
}	t_end;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		p_i;
	int		p_j;
	int		has_coll;
	int		count_moves;
	int		bonus;
	t_menu	menu;
	t_end	end_game;
	t_map	map;
	t_img	img;
}	t_game;

/* INIT FUNCTIONS */

void		init_all_stats(t_game *game, char *path);
void		init_game_stats(t_game *game);
void		init_game(char *path, t_game *game);
void		init_menu_window(t_game *game);
void		init_game_window(t_game *game);
void		init_end_game_window(t_game *game);
int			click_to_exit(t_game *game);

/* CHECK FUNCTIONS */

int			error_msg(char *str);
int			get_height(char *path, t_game *game);
void		check_ber(char *path);
void		check_map(t_game *game);
void		check_chars(t_game *game, char *path);

/* IMAGES FUNCTIONS */

int			render_images(t_game *game);
void		init_images(t_game *game);
void		put_image(t_game *game, int xyij[4]);
void		delete_images(t_game game);
void		do_death_animation(t_game *game);
void		do_water_animation(t_game *game);

/* GAME FUNCTIONS */

void		do_menu_window(t_game *game);
void		do_game(t_game *game);
void		move_player(t_game *game, int key);
void		end_game(t_game *game, int win);

/* EXIT FUNCTIONS */

int			click_to_exit_game(t_game *game);
int			click_to_exit_menu(t_game *game);
void		free_map(char **map);

#endif
