/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:05:06 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/28 15:13:20 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
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
	ft_printf("La posicion del player es x: %d, y: %d\n",
		game->player_x, game->player_y);
	return (0);
}
