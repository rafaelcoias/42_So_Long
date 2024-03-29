#ifndef IMAGES_H
# define IMAGES_H

/* GAME IMAGES */

# define WALL "include/images/game/wall.xpm"
# define EXIT "include/images/game/exit.xpm"
# define BACK_GRD "include/images/game/back_ground.xpm"
# define PLAYER "include/images/game/player.xpm"
# define PLAYER_W_COLL "include/images/game/player_w_coll.xpm"
# define COLL "include/images/game/collectable.xpm"
# define BONUS "include/images/game/bonus.xpm"
# define BLOCK "include/images/game/block.xpm"
# define TRANSPORT "include/images/game/transport.xpm"

/* MENU IMAGES */

# define MENU_TEST "include/images/game/menu_test.xpm"
# define MENU_PLAY "include/images/game/menu_play.xpm"
# define MENU_EXIT "include/images/game/menu_exit.xpm"

/* END GAME IMAGES */

# define WIN "include/images/game/winner_win.xpm"
# define LOSE "include/images/game/game_over_win.xpm"

/* NUMBERS IMAGES */

# define LINE "include/images/game/line.xpm"
# define MOV "include/images/game/MOV.xpm"
# define ES "include/images/game/ES.xpm"
# define SCO "include/images/game/SCO.xpm"
# define RE "include/images/game/RE.xpm"
# define NBR_PATH "include/images/numbers/0.xpm"
# define NBR_WIN_PATH "include/images/winnums/0.xpm"

/* ANIMATIONS */

# define DEATH_1 "include/images/animations/death_1.xpm"
# define DEATH_2 "include/images/animations/death_2.xpm"
# define DEATH_3 "include/images/animations/death_3.xpm"
# define DEATH_4 "include/images/animations/death_4.xpm"
# define DEATH_5 "include/images/animations/death_5.xpm"

# define WATER_1 "include/images/animations/water_1.xpm"
# define WATER_2 "include/images/animations/water_2.xpm"
# define WATER_3 "include/images/animations/water_3.xpm"
# define WATER_4 "include/images/animations/water_4.xpm"
# define WATER_5 "include/images/animations/water_5.xpm"

/* IMAGES STRUCT */

typedef struct s_img
{
	void	*mlx;
	int		width;
	void	*wall;
	void	*exit;
	void	*back_ground;
	void	*player_w_coll;
	void	*collectable;
	void	*bonus;
	void	*block;
	void	*transport;
	void	*line;
	void	*mov;
	void	*es;
	void	*sco;
	void	*re;
	void	*win;
	void	*lose;
	void	*menu_test;
	void	*menu_play;
	void	*menu_exit;
	void	*water[5];
	void	*player[6];
	void	*nbrs[10];
	void	*win_nbrs[10];
}	t_img;

#endif
