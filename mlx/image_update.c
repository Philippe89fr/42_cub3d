/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:02:30 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/17 18:35:10 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

/*
 * 🔥 my_pixel_put
 */
void	put_floor(t_data *data)
{
	int	i;
	int	j;
	int	color;

	color = ft_atoi(data->floor);
	i = MAP_HEIGHT / 2;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			my_pixel_put(data->img, j, i, color);
			j++;
		}
		i++;
	}
}

void	put_ceiling(t_data *data)
{
	int	i;
	int	j;
	int	color;

	color = ft_atoi(data->ceiling);
	i = 0;
	while (i < MAP_HEIGHT / 2)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			my_pixel_put(data->img, j, i, color);
			j++;
		}
		i++;
	}
}

void	update_img(t_data *data)
{
	data->ac = data->ac + 0;
	put_floor(data);
	put_ceiling(data);
	put_lines(data);
}

/*
 * All the checks for errors like
 *
 * 	~if (vars.mlx == NULL) exit(1);
 *
 * are not written to not clog te code!
 * But u know this stuff is a necessary evil 😂
 */
