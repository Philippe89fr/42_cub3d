/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator_god.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:55:48 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/17 18:34:17 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	liberator_godv2(t_data *data)
{
	if (data->south)
		mlx_destroy_image(data->mlx_ptr, data->south);
	if (data->north)
		mlx_destroy_image(data->mlx_ptr, data->north);
	if (data->west)
		mlx_destroy_image(data->mlx_ptr, data->west);
	if (data->east)
		mlx_destroy_image(data->mlx_ptr, data->east);
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->img)
	{
		if (data->img->img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
		free(data->img);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	liberator_god(t_data *data)
{
	if (data->input_tab2)
		ft_liberator_max(data->input_tab2);
	if (data->map)
		ft_liberator_max(data->map);
	if (data->big_map)
		ft_liberator_max(data->big_map);
	if (data->n_texture)
		free(data->n_texture);
	if (data->s_texture)
		free(data->s_texture);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->w_texture)
		free(data->w_texture);
	if (data->e_texture)
		free(data->e_texture);
	if (data->color_c)
		ft_liberator_max(data->color_c);
	if (data->color_f)
		ft_liberator_max(data->color_f);
	liberator_godv2(data);
}
