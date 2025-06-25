/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:10 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/17 17:44:34 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

int	get_largest_map_line(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

void	ft_fill_map_copy(char **map, char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			copy_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

char	**ft_get_square_map(char **map)
{
	int		size;
	int		i;
	char	**copy_map;

	size = 0;
	while (map[size])
		size++;
	copy_map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!copy_map)
		return (NULL);
	copy_map[size] = NULL;
	size = get_largest_map_line(map);
	i = 0;
	while (map[i])
	{
		copy_map[i] = (char *)malloc((sizeof(char)) * (size + 1));
		if (!map[i])
			return (NULL);
		ft_memset(copy_map[i], ' ', size);
		copy_map[i][size] = '\0';
		i++;
	}
	ft_fill_map_copy(map, copy_map);
	return (copy_map);
}

void	ft_printtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
