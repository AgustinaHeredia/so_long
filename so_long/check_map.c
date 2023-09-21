/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:29:05 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/21 15:22:49 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_char_valid(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] != 'P' && game->map[row][col] != 'E'
				&& game->map[row][col] != '0' && game->map[row][col] != '1'
				&& game->map[row][col] != 'C')
				error_exit("Error. Los argumentos del mapa no son válidos\n");
			col++;
		}
		row++;
	}
	return (0);
}

int	is_rectangle(t_game *game)
{
	int	x;
	int	y;
	int	size;

	size = ft_strlen(game->map[0]);
	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = ft_strlen(game->map[y]);
		if (x != size)
			error_exit("Error. El mapa facilitado no es un rectángulo\n");
		y++;
	}
	return (0);
}

int	perimeter_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
				error_exit("Error. El perimetro no es correcto\n");
			if (game->map[i][0] != 1 || game->map[i][game->width - 1] != '1')
				error_exit("Error. El perimetro no es correcto\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_resolt(t_game *game)
{
	char	**temp;
	int		count_colect;

	temp = create_copy_map(game->map, game->height, game->width);
	count_colect = 0;
	flood_fill(game, temp, game->player_x, game->player_y);
	if (count_colect == game->apple
		&& temp[game->player_x][game->player_y] == 'F')
	{
		free_map(temp, game->height);
		return (0);
	}
	else
	{
		free_map(temp, game->height);
		error_exit("Error. El mapa no tiene solución.\n");
	}
	return (0);
}
