/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:44:54 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/18 13:39:18 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_initimage(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, MAP_WIDTH, MAP_HEIGHT,
			"Cub3d baby");
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	data->img->img_pixels_ptr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_len,
			&data->img->endian);
	data->img->img_pixels_n = mlx_get_data_addr(data->north,
			&data->img->bits_per_pixel_n, &data->img->line_len_n,
			&data->img->endian_n);
	data->img->img_pixels_s = mlx_get_data_addr(data->south,
			&data->img->bits_per_pixel_s, &data->img->line_len_s,
			&data->img->endian_s);
	data->img->img_pixels_e = mlx_get_data_addr(data->east,
			&data->img->bits_per_pixel_e, &data->img->line_len_e,
			&data->img->endian_e);
	data->img->img_pixels_w = mlx_get_data_addr(data->west,
			&data->img->bits_per_pixel_w, &data->img->line_len_w,
			&data->img->endian_w);
	screen_distance(data);
	update_img(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
	return (true);
}

// mlx_hook(data->win_ptr, 2, 3, handle_input, data);
bool	start_game(t_data *data)
{
	if (!ft_initimage(data))
		return (false);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_hook(data->win_ptr, 33, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (data);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		liberator_god(data);
		exit(1);
	}
	else if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
		move_perso(data, keysym);
	else if (keysym == XK_Left || keysym == XK_Right)
		move_camera(data, keysym);
	screen_distance(data);
	update_img(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
	return (0);
}
