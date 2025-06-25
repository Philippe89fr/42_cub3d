/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pre_img_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:27 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/18 14:00:00 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_get_color_format(t_data *data)
{
	data->ceiling = ft_strjoin(data->color_c[0], data->color_c[1]);
	data->ceiling = ft_strjoin_free(data->ceiling, data->color_c[2]);
	if (!data->ceiling)
	{
		ft_printf("Malloc error: color to hex switch failed\n");
		return (false);
	}
	data->floor = ft_strjoin(data->color_f[0], data->color_f[1]);
	data->floor = ft_strjoin_free(data->floor, data->color_f[2]);
	if (!data->floor)
	{
		ft_printf("Malloc error: color to hex switch failed\n");
		return (false);
	}
	return (true);
}

void	get_direction(t_data *data)
{
	if (data->depart == 'E')
		data->direction = 90;
	else if (data->depart == 'W')
		data->direction = 270;
	else if (data->depart == 'S')
		data->direction = 180;
	else
		data->direction = 0;
}

void	init_tab_ray(t_data *data)
{
	int	i;

	i = 0;
	while (i < MAP_WIDTH)
	{
		data->tab_ray[i] = 0;
		i++;
	}
}

bool	init_t_img(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		return (malloc_error(), false);
	data->img->img_ptr = NULL;
	data->img->img_pixels_ptr = NULL;
	return (true);
}
