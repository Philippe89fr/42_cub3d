/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:34:11 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/17 18:34:40 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_init_data_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (false);
	data->north = mlx_xpm_file_to_image(data->mlx_ptr, data->n_texture,
			&data->img->width_n, &data->img->height_n);
	data->east = mlx_xpm_file_to_image(data->mlx_ptr, data->e_texture,
			&data->img->width_e, &data->img->height_e);
	data->south = mlx_xpm_file_to_image(data->mlx_ptr, data->s_texture,
			&data->img->width_s, &data->img->height_s);
	data->west = mlx_xpm_file_to_image(data->mlx_ptr, data->w_texture,
			&data->img->width_w, &data->img->height_w);
	if (!data->north || !data->east || !data->south || !data->west)
		return (false);
	return (true);
}
