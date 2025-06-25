/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing_second.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:22:46 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/18 14:14:04 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_iswhite_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

bool	ft_texture_xpm_verif(char *path)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
		i++;
	j = -1;
	while (ft_iswhite_space(path[i + j]) == true)
		j -= 1;
	if (i + j < 0 || path[i + j] != 'm')
		return (false);
	j -= 1;
	if (i + j < 0 || path[i + j] != 'p')
		return (false);
	j -= 1;
	if (i + j < 0 || path[i + j] != 'x')
		return (false);
	j -= 1;
	if (i + j < 0 || path[i + j] != '.')
		return (false);
	return (true);
}

bool	ft_malloc_texture_verif(t_data *data)
{
	if (!data->s_texture || !data->n_texture || !data->e_texture
		|| !data->w_texture || !data->color_c || !data->color_f)
		return (malloc_error(), false);
	if (!ft_texture_xpm_verif(data->n_texture)
		|| !ft_texture_xpm_verif(data->s_texture))
		return (ft_printf("Error.\nTexture format not .xpm.\n"), false);
	if (!ft_texture_xpm_verif(data->w_texture)
		|| !ft_texture_xpm_verif(data->e_texture))
		return (ft_printf("Error.\nTexture format not .xpm.\n"), false);
	return (true);
}

bool	map_is_last(char **input)
{
	int	i;

	i = 0;
	while (!only_1__0_or_space(input[i]))
		i++;
	while (input[i])
	{
		if (!only_1__0_or_space2(input[i]))
			return (false);
		i++;
	}
	return (true);
}
