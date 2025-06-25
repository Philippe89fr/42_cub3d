/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:10 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/17 18:37:44 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

int	ft_put_22(char **map, int i, int j, int count)
{
	if (map[i] && map[i][j + 1] &&
			(map[i][j + 1] == '0' || map[i][j + 1] == '1'))
	{
		map[i][j + 1] = '2';
		count++;
	}
	if (j > 0 && map[i][j - 1] &&
			(map[i][j - 1] == '0' || map[i][j - 1] == '1'))
	{
		map[i][j - 1] = '2';
		count++;
	}
	return (count);
}

int	ft_put_2(char **map, int i, int j)
{
	int	count;

	count = 0;
	if (map[i + 1] && map[i + 1][j] &&
			(map[i + 1][j] == '0' || map[i + 1][j] == '1'))
	{
		map[i + 1][j] = '2';
		count++;
	}
	if (i > 0 && map[i - 1][j] &&
			(map[i - 1][j] == '0' || map[i - 1][j] == '1'))
	{
		map[i - 1][j] = '2';
		count++;
	}
	count = ft_put_22(map, i, j, count);
	return (count);
}

int	ft_fload_2a(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i] && map[i][j] && map[i][j] == '2')
				k = k + ft_put_2(map, i, j);
			j++;
		}
		i++;
	}
	return (k);
}

void	ft_fload_2b(char **map)
{
	int	k;

	k = 1;
	while (k != 0)
	{
		k = ft_fload_2a(map);
	}
}

bool	ft_floodfill(t_data *data)
{
	char	**map2;

	map2 = ft_table_strdup(data->map);
	if (!map2)
		return (false);
	map2[data->y_start][data->x_start] = '2';
	ft_fload_2b(map2);
	if (!ft_map_compact(map2))
	{
		ft_liberator_max(map2);
		return (false);
	}
	ft_liberator_max(map2);
	return (true);
}
