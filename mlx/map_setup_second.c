/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:26:10 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/18 14:05:49 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

/*Verifie qu'il n'y a pas que des espaces dans la ligne*/
bool	not_all_space(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ')
			return (true);
		i++;
	}
	return (false);
}

/*Cherche la premiere ligne de la map qui a que des 1 et 0 ou space*/
bool	only_1__0_or_space(char *line)
{
	int	i;

	i = 0;
	if (!not_all_space(line))
		return (false);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'S' && line[i] != 'E')
			return (false);
		i++;
	}
	return (true);
}

bool	only_1__0_or_space2(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'S' && line[i] != 'E')
			return (false);
		i++;
	}
	return (true);
}

void	replace_backslashn(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
}
