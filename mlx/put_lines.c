/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:02:31 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/17 18:30:11 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color2(t_data *data, int x, int y, char c)
{
	int	color;
	int	offset;

	if (c == 'S')
	{
		offset = (data->img->line_len_s * y) + (x * (data->img->bits_per_pixel_s
					/ 8));
		color = *((unsigned int *)(offset + data->img->img_pixels_s));
	}
	else if (c == 'E')
	{
		x = data->img->width_n - x - 1;
		offset = (data->img->line_len_e * y) + (x * (data->img->bits_per_pixel_e
					/ 8));
		color = *((unsigned int *)(offset + data->img->img_pixels_e));
	}
	else
		color = 33;
	return (color);
}

int	get_pixel_color(t_data *data, double pourcentage_height, double taille,
		int line_number)
{
	int		offset;
	int		color;
	int		x;
	int		y;
	char	c;

	taille = taille + 1;
	c = data->tab_shap[line_number];
	y = pourcentage_height * data->img->height_n;
	x = data->tab_pos[line_number] * data->img->width_n;
	if (c == 'W')
	{
		offset = (data->img->line_len_w * y) + (x * (data->img->bits_per_pixel_w
					/ 8));
		color = *((unsigned int *)(offset + data->img->img_pixels_w));
	}
	else if (c == 'N')
	{
		offset = (data->img->line_len_n * y) + (x * (data->img->bits_per_pixel_n
					/ 8));
		color = *((unsigned int *)(offset + data->img->img_pixels_n));
	}
	else
		color = get_pixel_color2(data, x, y, c);
	return (color);
}

double	get_pourcentage_height(double start, double i, double end,
		double taille)
{
	double	pourcentage_height;
	double	debut_big_img;
	double	fin_big_img;
	double	ecart;

	if (taille <= 100)
		pourcentage_height = (i - start) / (end - start);
	else
	{
		debut_big_img = (1 - (100 / taille)) / 2;
		fin_big_img = 1 - debut_big_img;
		ecart = (fin_big_img - debut_big_img) / MAP_HEIGHT;
		pourcentage_height = debut_big_img + i * ecart;
	}
	return (pourcentage_height);
}

void	put_line(t_data *data, double taille, int line_number)
{
	int		color;
	int		start;
	int		end;
	double	pourcentage_height;
	int		i;

	i = 0;
	if (taille < 100)
	{
		start = (MAP_HEIGHT * (100 - taille) / 2) / 100;
		end = MAP_HEIGHT - start;
	}
	else
	{
		start = 0;
		end = MAP_HEIGHT;
	}
	while (start + i < end)
	{
		pourcentage_height = get_pourcentage_height(start, start + i, end,
				taille);
		color = get_pixel_color(data, pourcentage_height, taille, line_number);
		my_pixel_put(data->img, line_number, start + i, color);
		i++;
	}
}

void	put_lines(t_data *data)
{
	int		i;
	double	taille2;

	i = 0;
	taille2 = 0;
	while (i < MAP_WIDTH)
	{
		put_line(data, data->pourcentage_tab[i], i);
		i++;
	}
}
