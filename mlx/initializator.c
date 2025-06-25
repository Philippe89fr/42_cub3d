/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:27 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/18 14:00:23 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_size(t_data *data)
{
	int	i;

	i = 0;
	data->map_width = ft_strlen(data->map[0]);
	while (data->map[i])
		i++;
	data->map_height = i;
}

void	pre_init(t_data *data)
{
	data->x_start = 0;
	data->y_start = 0;
	data->big_map = NULL;
	data->south = NULL;
	data->east = NULL;
	data->north = NULL;
	data->west = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->color_c = NULL;
	data->ceiling = NULL;
	data->color_f = NULL;
	data->floor = NULL;
	data->s_texture = NULL;
	data->n_texture = NULL;
	data->e_texture = NULL;
	data->w_texture = NULL;
	data->input_tab2 = NULL;
	data->map = NULL;
	data->img = NULL;
	init_tab_ray(data);
}

bool	ft_init_struct_second(t_data *data)
{
	data->x_perso = (data->x_start + 0.5);
	data->y_perso = (data->y_start + 0.5);
	data->s_texture = get_dir_str(data, 'S', 'O');
	data->n_texture = get_dir_str(data, 'N', 'O');
	data->e_texture = get_dir_str(data, 'E', 'A');
	data->w_texture = get_dir_str(data, 'W', 'E');
	data->color_c = ft_mega_split(get_color_str(data, 'C'), ", ");
	data->color_f = ft_mega_split(get_color_str(data, 'F'), ", ");
	if (!ft_malloc_texture_verif(data))
		return (false);
	if (!ft_parsing_color(data))
		return (ft_printf("Error.\nColor issue.\n"), false);
	if (!ft_get_color_format(data))
		return (false);
	if (!init_t_img(data))
		return (false);
	if (!ft_init_data_mlx(data))
		return (ft_printf("Error.\nInitialisation data mlx failed.\n"), false);
	return (true);
}

bool	ft_init_struct(t_data *data)
{
	pre_init(data);
	data->input_tab2 = ft_get_tab(data->input_file);
	if (!data->input_tab2)
		return (ft_printf("Error.\nEmpty dataset.\n"), false);
	if (!ft_doc_parsing(data))
		return (false);
	data->map = ft_get_map(data->input_tab2);
	ft_get_start_position(data);
	if (!ft_parsing_map(data))
		return (ft_printf("Error.\nMap incorrect.\n"), false);
	get_map_size(data);
	get_direction(data);
	if (!verif_occurence_color_texture(data))
		return (false);
	if (!ft_init_struct_second(data))
		return (false);
	return (true);
}
