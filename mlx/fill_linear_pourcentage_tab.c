/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_linear_pourcentage_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:11:46 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/17 18:43:13 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_samee_wall(t_data *data, int i, int j)
{
	double	difference;

	if (i < 1 || j == i)
		return (true);
	difference = data->tab_ray[i] - data->tab_ray[i - 1];
	if (difference < 1 && difference > -1)
	{
		if (data->tab_shap[i] == data->tab_shap[i - 1])
			return (true);
		else
			return (false);
	}
	return (false);
}

void	fill_wall_linear2(t_data *data, double i, double j, double dif)
{
	double	pourcentage_start;
	double	mult;
	double	increment;
	int		k;
	double	l;

	k = j / 1;
	pourcentage_start = 100.0 / data->tab_square_ray[k];
	l = 0;
	k = j / 1;
	while (l <= i - j + 1)
	{
		if (i == j)
			mult = l;
		else
			mult = l / (i - j);
		increment = dif * mult;
		data->pourcentage_tab[k] = pourcentage_start + increment;
		l++;
		k++;
	}
}

void	fill_wall_linear(t_data *data, double i, double j)
{
	double	pourcentage_start;
	double	pourcentage_end;
	double	dif;
	int		k;

	k = j / 1;
	pourcentage_start = 100.0 / data->tab_square_ray[k];
	k = i / 1;
	pourcentage_end = 100.0 / data->tab_square_ray[k];
	dif = pourcentage_end - pourcentage_start;
	fill_wall_linear2(data, i, j, dif);
}

void	fill_linear_pourcentage_tab(t_data *data)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < MAP_WIDTH)
	{
		j = i;
		while (is_samee_wall(data, i, j) && i + 1 < MAP_WIDTH)
			i++;
		fill_wall_linear(data, i - 1, j);
		i++;
		k++;
	}
}
