/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:46:29 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/22 12:28:15 by agheredi         ###   ########.fr       */
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
	free(game);
	perror(str);
	exit (EXIT_FAILURE);
}
