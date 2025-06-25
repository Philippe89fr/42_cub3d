/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:27:51 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/18 14:14:53 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	deplacement(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = y / 1;
	j = x / 1;
	if (data->map[i][j] == '1')
		return ;
	data->x_perso = x;
	data->y_perso = y;
	data->map[i][j] = 'X';
}

void	move(t_data *data, int direction, double x, double y)
{
	int	i;
	int	j;

	i = (data->y_perso / 1);
	j = (data->x_perso / 1);
	if ((direction >= 90 && direction < 180))
		x = data->x_perso + sin(get_rad(90 - (direction % 90))) / 5;
	else if ((direction >= 270 && direction < 360))
		x = data->x_perso - sin(get_rad(90 - (direction % 90))) / 5;
	else if ((direction >= 0 && direction < 90))
		x = data->x_perso + sin(get_rad(direction % 90)) / 5;
	else if ((direction >= 180 && direction < 270))
		x = data->x_perso - sin(get_rad(direction % 90)) / 5;
	if ((direction >= 90 && direction < 180))
		y = data->y_perso + sin(get_rad(direction % 90)) / 5;
	else if ((direction >= 270 && direction < 360))
		y = data->y_perso - sin(get_rad(direction % 90)) / 5;
	else if ((direction >= 0 && direction < 90))
		y = data->y_perso - sin(get_rad(90 - (direction % 90))) / 5;
	else if ((direction >= 180 && direction < 270))
		y = data->y_perso + sin(get_rad(90 - (direction % 90))) / 5;
	deplacement(x, y, data);
}

void	move_perso2(t_data *data, int keysym)
{
	int	direction2;

	if (keysym == 'd')
	{
		direction2 = data->direction + 90;
		if (direction2 >= 360)
			direction2 = direction2 - 360;
		move(data, direction2, 0, 0);
	}
	if (keysym == 's')
	{
		direction2 = data->direction + 180;
		if (direction2 > 360)
			direction2 = direction2 - 360;
		move(data, direction2, 0, 0);
	}
}

void	move_perso(t_data *data, int keysym)
{
	int	direction2;

	if (keysym == 'w')
	{
		direction2 = data->direction;
		move(data, direction2, 0, 0);
	}
	if (keysym == 'a')
	{
		direction2 = data->direction - 90;
		if (direction2 < 0)
			direction2 = 360 + direction2;
		move(data, direction2, 0, 0);
	}
	move_perso2(data, keysym);
}

void	move_camera(t_data *data, int keysym)
{
	if (keysym == XK_Left)
	{
		data->direction -= 5;
		if (data->direction < 0)
			data->direction = 360 + data->direction;
	}
	if (keysym == XK_Right)
	{
		data->direction += 5;
		if (data->direction > 360)
			data->direction = data->direction - 360;
	}
}
