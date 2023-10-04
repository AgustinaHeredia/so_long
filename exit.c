/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:46:29 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/04 15:01:33 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_free_exit(t_game *game, char *str)
{
	if (game->map)
		free_map(game->map);
	free(game);
	perror(str);
	exit (EXIT_FAILURE);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	free(game);
	ft_printf("Ooohhh... has salido del juego\n");
	exit(0);
}

void	clear_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	free(game);
	ft_printf("Felicidades!!!!\n");
	ft_printf("Has llegado a casa de la Abuelita <3 <3\n");
	exit(0);
}
