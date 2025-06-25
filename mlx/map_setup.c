/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:26:10 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/18 14:06:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

int	ft_get_tab2(char **tab, int fd)
{
	char	*buf;
	int		i;

	i = 0;
	buf = get_next_line(fd);
	if (!buf)
		return (malloc_error(), free(tab), -1);
	while (buf)
	{
		tab[i] = ft_strdup(buf);
		free(buf);
		if (!tab[i])
			return (malloc_error(), ft_liberator_part(tab, i), -1);
		buf = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**ft_get_tab(char *fichier)
{
	int		fd;
	char	**tab;
	int		i;

	tab = (char **)malloc(300 * sizeof(char *));
	if (!tab)
		return (malloc_error(), free(tab), NULL);
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (free(tab), NULL);
	i = ft_get_tab2(tab, fd);
	if (i == -1)
		return (NULL);
	tab[i] = NULL;
	replace_backslashn(tab);
	close(fd);
	return (tab);
}

/*compte le nombre de ligne liees a la map*/
int	count_map_related_lines(char **tab)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (tab[i])
	{
		if (only_1__0_or_space(tab[i]))
			res++;
		i++;
	}
	return (res);
}

/*verifie qu il n y a pas de ligne incorrect entre les lignes de la map*/
bool	map_related_lines_all_together(char **tab)
{
	int	i;
	int	j;
	int	tot;

	i = 0;
	j = 0;
	tot = count_map_related_lines(tab);
	while (!only_1__0_or_space(tab[i]))
		i++;
	while (only_1__0_or_space(tab[i]))
	{
		i++;
		j++;
	}
	if (j == tot)
		return (true);
	return (false);
}

char	**ft_get_map(char **tab)
{
	int		i;
	int		j;
	int		tot;
	char	**map;
	char	**map2;

	i = 0;
	j = 0;
	tot = count_map_related_lines(tab);
	while (!only_1__0_or_space(tab[i]))
		i++;
	map = (char **)malloc((tot + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (j < tot)
	{
		map[j] = ft_strdup(tab[i + j]);
		j++;
	}
	map[j] = NULL;
	map2 = ft_get_square_map(map);
	ft_liberator_max(map);
	return (map2);
}
