/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:16 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/02 13:55:49 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define IMG_PX		64

typedef struct s_game
{
	int		width;
	int		height;
	char	*strbigline;
	char	**map;
	int		player;
	int		exit;
	int		player_x;
	int		player_y;
	int		apple;
	int		player_move;
	int		count_colec;
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_player_b;
	void	*img_player_f;
	void	*img_player_r;
	void	*img_player_l;
	void	*img_collectable;
	void	*img_exit;
}	t_game;

int		main(int argc, char **argv);
void	error_exit(char *str);
int		check_arg_and_fd(int argc, char **argv);
void	read_map(int fd, t_game *game);
void	flood_fill(t_game *game, char **temp, int x, int y);
char	**create_copy_map(char **map, int height);
void	free_map(char **tab, int rows);
int		all_char_valid(t_game *game);
int		has_exit_player_colect(t_game *game);
int		is_rectangle(t_game *game);
int		perimeter_check(t_game *game);
int		check_map_resolt(t_game *game);
void	check_map(t_game *game);
void	error_free_exit(t_game *game, char *str);
void	upload_img(t_game *game);
void	paint_backgroud(t_game *game);
void	setting_map(t_game *game);
void	init_game(t_game *game);
int		press_key(int key_code, t_game *game);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	exit_game(t_game *game);
void	clear_game(t_game *game);

#endif