/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:05:06 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/02 15:29:54 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	key_press(int keycode, t_game *game)
{
	static int	a;

	a = 0;
	(void)keycode;
	if (keycode == KEY_W)
		game->player_y++;
	else if (keycode == KEY_S)
		game->player_y--;
	else if (keycode == KEY_A)
		game->player_x--;
	else if (keycode == KEY_D)
		game->player_x++;
	else if (keycode == KEY_ESC)
		exit(0);
	else if (valid_move(game) == 0)
		game->player_move++;
	ft_printf("La posicion del player es x: %d, y: %d\n",
		game->player_x, game->player_y);
	return (0);
}*/

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

void	move_w(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (x - 1 >= 0 && game->map[x - 1][y] != '1' && game->map[x - 1][y] != 'E')
	{
		if (game->map[x - 1][y] == 'C')
			game->count_colec++;
		game->map[x][y] = '0';
		game->map[x - 1][y] = 'P';
		game->player_move++;
		game->player_x--;
		printf("Manzanas recolectadas%d\n", game->count_colec);
		printf("Nro. movimientos player%d\n", game->player_move);
		paint_backgroud(game);
		setting_map(game);
		if (game->map[x - 1][y] == 'E' && game->count_colec == game->apple)
			clear_game(game);
	}
}

void	move_a(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (x - 1 >= 0 && game->map[x][y -1] != '1' && game->map[x][y -1] != 'E')
	{
		if (game->map[x][y -1] == 'C')
			game->count_colec++;
		game->map[x][y] = '0';
		game->map[x][y -1] = 'P';
		game->player_move++;
		game->player_y--;
		printf("Manzanas recolectadas%d\n", game->count_colec);
		printf("Nro. movimientos player%d\n", game->player_move);
		paint_backgroud(game);
		setting_map(game);
		if (game->map[x][y -1] == 'E' && game->count_colec == game->apple)
			clear_game(game);
	}
}

void	move_d(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (x - 1 >= 0 && game->map[x][y + 1] != '1' && game->map[x][y + 1] != 'E')
	{
		if (game->map[x][y + 1] == 'C')
			game->count_colec++;
		game->map[x][y] = '0';
		game->map[x][y + 1] = 'P';
		game->player_move++;
		game->player_y++;
		printf("Manzanas recolectadas: %d\n", game->count_colec);
		printf("Nro. movimientos player: %d\n", game->player_move);
		paint_backgroud(game);
		setting_map(game);
		if (game->map[x][y + 1] == 'E' && game->count_colec == game->apple)
			clear_game(game);
	}
}

void	move_s(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (x - 1 >= 0 && game->map[x + 1][y] != '1' && game->map[x + 1][y] != 'E')
	{
		if (game->map[x + 1][y] == 'C')
			game->count_colec++;
		game->map[x][y] = '0';
		game->map[x + 1][y] = 'P';
		game->player_move++;
		game->player_x++;
		printf("Manzanas recolectadas%d\n", game->count_colec);
		printf("Nro. movimientos player%d\n", game->player_move);
		paint_backgroud(game);
		setting_map(game);
		if (game->map[x + 1][y] == 'E' && game->count_colec == game->apple)
			clear_game(game);
	}
}
