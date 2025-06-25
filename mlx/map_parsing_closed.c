/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_closed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:22:00 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/18 14:03:06 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

int	ft_table_strdup_space2(char **dest, int j, char **src)
{
	int	i;

	i = 1;
	while (src[i - 1])
	{
		dest[i] = ft_strdup(src[i - 1]);
		if (!dest[i])
			return (ft_liberator_part(dest, i), malloc_error(), 1);
		i++;
	}
	dest[i + 1] = NULL;
	dest[i] = (char *)malloc(sizeof(char) * (j + 1));
	if (!dest[i])
		return (ft_liberator_part(dest, i), malloc_error(), 1);
	ft_memset(dest[i], ' ', (size_t)j);
	dest[i][j] = '\0';
	return (0);
}

char	**ft_table_strdup_space(char **src)
{
	char	**dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char **)malloc((i + 3) * sizeof(char *));
	if (!dest)
		return (malloc_error(), NULL);
	dest[0] = (char *)malloc(sizeof(char) * (ft_strlen(src[0]) + 1));
	if (!dest[0])
		return (malloc_error(), NULL);
	ft_memset(dest[0], ' ', (size_t)ft_strlen(src[0]));
	dest[0][ft_strlen(src[0])] = '\0';
	if (ft_table_strdup_space2(dest, ft_strlen(src[0]), src))
		return (NULL);
	return (dest);
}

bool	ft_map_close_check_verif(char **map2, int i, int j)
{
	if (map2[i][j] == 'N' || map2[i][j] == 'W' || map2[i][j] == 'S'
		|| map2[i][j] == 'E')
		map2[i][j] = '2';
	if (map2[i][j] == '0' && (map2[i + 1][j] == ' ' || map2[i - 1][j] == ' '
			|| map2[i][j + 1] == ' ' || (j > 0 && map2[i][j - 1] == ' ')
			|| (j == 0)))
		return (false);
	if (map2[i][j] == '0' && (map2[i + 1][j] == '\0' || map2[i - 1][j] == '\0'
			|| map2[i][j + 1] == '\0' || (j > 0 && map2[i][j - 1] == '\0')
			|| (j == 0)))
		return (false);
	if (map2[i][j] == '2' && (map2[i + 1][j] == ' ' || map2[i - 1][j] == ' '
			|| map2[i][j + 1] == ' ' || (j > 0 && map2[i][j - 1] == ' ')
			|| (j == 0)))
		return (false);
	if (map2[i][j] == '2' && (map2[i + 1][j] == '\0' || map2[i - 1][j] == '\0'
			|| (j == 0) || map2[i][j + 1] == '\0'
			|| (j > 0 && map2[i][j - 1] == '\0')))
		return (false);
	return (true);
}

bool	ft_map_close_check(t_data *data)
{
	int		i;
	int		j;
	char	**map2;

	i = 0;
	map2 = ft_table_strdup_space(data->map);
	if (!map2)
		return (malloc_error(), false);
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			if (!ft_map_close_check_verif(map2, i, j))
				return (ft_liberator_max(map2), false);
			j++;
		}
		j = 0;
		i++;
	}
	ft_liberator_max(map2);
	return (true);
}
