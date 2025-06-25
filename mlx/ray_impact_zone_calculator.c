/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_impact_zone_calculator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:02:30 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/17 18:28:30 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_pos(t_data *data, double direction, int i)
{
	double	result;

	if (data->tab_shap[i] == 'N' || data->tab_shap[i] == 'S')
	{
		if ((direction >= 270 || direction < 90))
			result = data->x_ray_impact[i];
		else
			result = 1.0 - data->x_ray_impact[i];
	}
	else
	{
		if ((direction >= 0 && direction < 180))
			result = 1.0 - data->y_ray_impact[i];
		else
			result = data->y_ray_impact[i];
	}
	return (result);
}
