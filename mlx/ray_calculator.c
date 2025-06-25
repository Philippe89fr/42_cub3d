/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:02:30 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/18 14:15:20 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	slow_move(t_data *data, double direction)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	if ((direction >= 90 && direction < 180))
		x = data->x_test + sin(get_rad(90 - (direction - 90))) / 1000;
	else if ((direction >= 270 && direction < 360))
		x = data->x_test - sin(get_rad(90 - (direction - 270))) / 1000;
	else if ((direction >= 0 && direction < 90))
		x = data->x_test + sin(get_rad(direction)) / 1000;
	else if ((direction >= 180 && direction < 270))
		x = data->x_test - sin(get_rad(direction - 180)) / 1000;
	if ((direction >= 90 && direction < 180))
		y = data->y_test + sin(get_rad(direction - 90)) / 1000;
	else if ((direction >= 270 && direction < 360))
		y = data->y_test - sin(get_rad(direction - 270)) / 1000;
	else if ((direction >= 0 && direction < 90))
		y = data->y_test - sin(get_rad(90 - (direction))) / 1000;
	else if ((direction >= 180 && direction < 270))
		y = data->y_test + sin(get_rad(90 - (direction - 180))) / 1000;
	data->x_test = x;
	data->y_test = y;
	return ;
}

double	ray_calculator(t_data *data, double direction)
{
	double	distance;

	distance = 0;
	data->x_test = data->x_perso;
	data->y_test = data->y_perso;
	while (!is_wall(data->x_test, data->y_test, data))
	{
		distance += 0.001;
		slow_move(data, direction);
	}
	return (distance);
}

/*on recule ou avance en fonction de la direction pour
voir si on est dans un mur en fonction cela nous indique la shape
*/
char	get_shap(t_data *data, double direction)
{
	if ((direction >= 0 && direction < 180))
		data->x_test -= 0.001;
	else
		data->x_test += 0.001;
	if (is_wall(data->x_test, data->y_test, data))
	{
		if ((direction >= 0 && direction < 180))
			data->x_test += 0.001;
		else
			data->x_test -= 0.001;
		if (direction >= 90 && direction < 270)
			return ('N');
		return ('S');
	}
	else
	{
		if ((direction >= 0 && direction < 180))
			data->x_test += 0.001;
		else
			data->x_test -= 0.001;
		if (direction >= 180)
			return ('E');
		return ('W');
	}
}

/*
ray_calculator = classic rays
modf -> prend la partie decimale
get_pos
	-> zone d'impact de l'image pour plus tard pouvoir dessiner les
	murs correctements
ray_calculator_square -> calcule de ray different,
	en fonction d un plan fixe perpendiculaire a la vue du perso
*/

void	el_calculator(t_data *data, double direction, double increment,
		double angle)
{
	double	partie_entiere;
	int		i;

	i = 0;
	while (i < MAP_WIDTH)
	{
		data->tab_ray[i] = ray_calculator(data, direction);
		data->x_ray_impact[i] = modf(data->x_test, &partie_entiere);
		data->y_ray_impact[i] = modf(data->y_test, &partie_entiere);
		data->tab_shap[i] = get_shap(data, direction);
		data->tab_pos[i] = get_pos(data, direction, i);
		data->tab_square_ray[i] = ray_calculator_square(data, angle, i);
		direction = direction + increment;
		if (i < MAP_WIDTH / 2)
			angle = angle + increment;
		else
			angle = angle - increment;
		if (direction > 360)
			direction = direction - 360;
		i++;
	}
}

void	screen_distance(t_data *data)
{
	double	direction;
	double	increment;
	double	angle;

	increment = POV / MAP_WIDTH;
	direction = data->direction - (POV / 2);
	angle = (180 - POV) / 2;
	if (direction < 0)
		direction = 360 + direction;
	el_calculator(data, direction, increment, angle);
	data->tab_shap[MAP_WIDTH] = '\0';
	fill_linear_pourcentage_tab(data);
}
