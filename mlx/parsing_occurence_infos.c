/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_occurence_infos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:22:46 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/17 18:31:54 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

bool	verif_texture_no_so_ea_we(t_data *data, char a, char b)
{
	int (i) = 0;
	int (j) = 0;
	int (verif) = 0;
	while (data->input_tab2[i])
	{
		j = 0;
		while (data->input_tab2[i][j + 1])
		{
			if (data->input_tab2[i][j] == a && data->input_tab2[i][j + 1] == b)
			{
				verif += 1;
				i++;
				if (!data->input_tab2[i])
					break ;
				j = -1;
			}
			j++;
		}
		i++;
	}
	if (verif != 1)
		return (false);
	return (true);
}

bool	verif_color_c_f(t_data *data, char c)
{
	int (i) = 0;
	int (j) = 0;
	int (verif) = 0;
	while (data->input_tab2[i])
	{
		j = 0;
		while (data->input_tab2[i][j + 1])
		{
			if (data->input_tab2[i][j] == c)
			{
				verif += 1;
				i++;
				if (!data->input_tab2[i])
					break ;
				j = -1;
			}
			j++;
		}
		i++;
	}
	if (verif != 1)
		return (false);
	return (true);
}

bool	verif_occurence_color_texture(t_data *data)
{
	if (!verif_color_c_f(data, 'C') || !verif_color_c_f(data, 'F'))
	{
		ft_printf("Error.\nToo many");
		ft_printf("/ Too few occurence of 'C' and 'F' in file.\n");
		return (false);
	}
	if (!verif_texture_no_so_ea_we(data, 'E', 'A')
		|| !verif_texture_no_so_ea_we(data, 'S', 'O'))
	{
		ft_printf("Error.\nToo many");
		ft_printf("/ Too few occurence of textures in file.\n");
		return (false);
	}
	if (!verif_texture_no_so_ea_we(data, 'N', 'O')
		|| !verif_texture_no_so_ea_we(data, 'W', 'E'))
	{
		ft_printf("Error.\nToo many");
		ft_printf("/ Too few occurence of textures in file.\n");
		return (false);
	}
	return (true);
}
