/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:10:19 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/26 15:33:44 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, char **temp, int x, int y)
{
	if (x < 0 || x >= game->height || y < 0 || y >= game->width
		|| temp[x][y] == '1' || temp[x][y] == 'F')
		return ;
	temp[x][y] = 'F';
	flood_fill(game, temp, (x + 1), y);
	flood_fill(game, temp, (x - 1), y);
	flood_fill(game, temp, x, (y + 1));
	flood_fill(game, temp, x, (y - 1));
}

char	**create_copy_map(char **map, int height)
{
	char	**temp;
	int		i;

	temp = (char **)malloc((height + 1) * sizeof(char *));
	if (!temp)
		error_exit("Error. No se ha podido asignar memoria al map Temp\n");
	i = 0;
	while (i < height)
	{
		temp[i] = ft_strdup(map[i]);
		if (!temp[i])
		{
			free_map(temp, i);
			error_exit("Error. No se ha podido asignar memoria en mapTemp\n");
		}
		i++;
	}
	temp[height] = NULL;
	return (temp);
}

void	free_map(char **tab, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
