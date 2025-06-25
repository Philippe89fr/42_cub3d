/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:22:00 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/18 14:03:23 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

bool	ft_parsing_map(t_data *data)
{
	if (!ft_one_entry(data->map, data))
		return (false);
	if (!ft_floodfill(data))
		return (false);
	if (!ft_map_close_check(data))
		return (false);
	return (true);
}

void	malloc_error(void)
{
	write(2, "malloc Error.\n", 14);
}

void	ft_get_start_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'W' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'N' || data->map[i][j] == 'E')
			{
				data->x_start = j;
				data->y_start = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

bool	ft_one_entry(char **map, t_data *data)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'N'
				|| map[i][j] == 'E')
			{
				data->depart = map[i][j];
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (false);
	return (true);
}

bool	ft_map_compact(char **map2)
{
	int	i;
	int	j;

	i = 1;
	while (map2[i])
	{
		j = 1;
		while (map2[i][j])
		{
			if (map2[i][j] != '2' && map2[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
