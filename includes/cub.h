/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:35:55 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 13:42:49 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>

# define WALL 0x00F0F0F0
# define DOOR_CLOSED 0xFFFF00
# define DOOR_OPEN 0x76FF03
# define SPELL 0xAA00FF
# define FLOOR 0x00000000
# define PLAYER 0x00FF0000

typedef struct s_imgTemp
{
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	int		*addr;
	int		y;
	int		x;
}				t_imgTemp;

typedef struct s_math
{
	char		playerdir;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldTime;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;

	int			mapX;
	int			maxX;
	int			mapY;
	int			maxY;

	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;

	double		stepX;
	double		stepY;
	double		hit;
	double		side;
	double		lineHeight;
	double		drawStart;
	double		drawEnd;

	double		frameTime;
	double		moveSpeed;
	double		rotSpeed;
	double		oldDirX;
	double		oldPlaneX;

	double		spritePosX;
	double		spritePosY;
}				t_math;

typedef struct s_key
{
	bool	upFlag;
	bool	downFlag;
	bool	leftFlag;
	bool	rightFlag;
	bool	arrowLeftFlag;
	bool	arrowRightFlag;
	bool	door;
	bool	doorclose;
	bool	sprint;
}				t_key;

typedef struct s_minimap
{
	int	a;
	int	b;
	int	pa;
	int	pb;
	int	o;
	int	u;
}				t_minimap;

typedef struct s_sprite
{
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			spriteDistanceFromGround;
	int			vMoveScreen;
	int			sizeFactor;
	int			spriteHeight;
	int			spriteWidth;
	int			drawStartY;
	int			drawEndY;
	int			drawStartX;
	int			drawEndX;
	int			texX;
	int			texY;
	int			d;
	int			color;
	double		ZBuffer[1680];
}		t_sprite;

typedef struct s_texture
{
	int			buff[1200][1680];
	int			**texture;
	double		wallX;
	int			texX;
	double		step;
	double		texPos;
	int			texY;
	int			texColor;
}				t_tex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	void		*floor;
	long		floorcode;
	void		*ceilling;
	long		ceillingcode;
	char		**map;
	double		win_width;
	double		win_height;
	void		*img;
	void		*img_tex;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_key		*key;
	t_math		*calc;
	t_sprite	*sprite;
	t_minimap	*minimap;
	t_tex		*tex;
	bool		spelltaken;
	int			global_count;
	int			spellNumber;
}				t_vars;

int			logic(t_vars *vars);
void		ft_free(t_vars *data);

/* INIT */
t_math		*ft_init_calc(t_vars *data);
t_vars		*ft_get_vars(char **data);
void		ft_init_minimap(t_vars *data);
t_key		*ft_init_key(t_vars *data);
t_sprite	*ft_init_sprite(t_vars *data);
t_tex		*ft_init_texture(t_vars *data);
void		ft_init_location(t_vars *re);
/* INIT */

/* HOOKS */
int			set_keyFlag_true(int keycode, t_vars *vars);
int			set_keyFlag_false(int keycode, t_vars *vars);
int			close_window(void);
/* HOOKS */

/* MATH */
void		ft_rayPosition_and_Direction(t_vars *vars, int x);
void		ft_step_and_sideDistance(t_vars *vars);
void		ft_DDA_algorithm(t_vars *vars);
void		ft_drawStart_and_drawEnd(t_vars *vars);
/* MATH */

/* DRAW */
void		ft_crosshair(t_vars *vars);

void		draw(t_vars *vars);

void		ft_floor_ceilling(t_vars *vars, int x);

void		ft_minimap(t_vars *vars);

void		ft_draw_sprite(t_vars *vars);
void		ft_sprite_animation(t_vars *vars);

void		ft_draw_texture(t_vars *vars, int x);
void		load_texture(t_vars *vars);
void		ft_sprint_spell(t_vars *vars);
/* DRAW */

/* MOVEMENT */
void		ft_movement(t_vars *vars);

void		ft_walk_backwards(t_vars *vars);
void		ft_walk_right(t_vars *vars);
void		ft_walk_left(t_vars *vars);
void		ft_walk_forward(t_vars *vars);
/* MOVEMENT */

/* DOOR */
int			ft_isdoor(t_vars *vars);
void		ft_isdoor_open(t_vars *vars);
int			ft_validate_distance_to_door(t_vars *vars);
/* DOOR */

//validate map
void		ft_get_location(t_vars *re, char **data);
void		ft_error(int i);
int			ft_getsize_array(char **data);
void		ft_check_location(t_vars *re);
void		ft_row_check(char *s);
void		ft_middle_row_check(char *s);
void		ft_character_check(char **map);
void		ft_player_check(char **map);
void		ft_potion_check(char **map);
int			ft_getsize_array(char **data);
int			ft_get_length_map(char **map);
int			ft_check_surrounded(char **map, int i, int x);
void		ft_check_closed_walls(char **map);
void		ft_validate_map(char **map);
void		ft_get_colour_code(void *input, long *returncode);

//read
char		*ft_read_loop(int bytesred, char buff[2], int fd);
char		*ft_readmap(char *file);

//mlx
int			logic(t_vars *vars);
void		ft_mlx_init(t_vars *data);
void		ft_game_start(t_vars *data);
t_vars		*ft_init_data_structure(char **parsing);

#endif
