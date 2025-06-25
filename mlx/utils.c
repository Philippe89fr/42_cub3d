/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:27:51 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/18 14:15:26 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	liberator_god(data);
	exit(1);
}

double	get_rad(double angle)
{
	double	rad;

	rad = angle * M_PI / 180.0;
	return (rad);
}

bool	is_wall(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = y / 1;
	j = x / 1;
	if (data->map[i][j] == '1')
		return (true);
	data->x_test = x;
	data->y_test = y;
	return (false);
}

double	ray_calculator_square(t_data *data, double angle, int i)
{
	return (data->tab_ray[i] * sin(get_rad(angle)));
}
