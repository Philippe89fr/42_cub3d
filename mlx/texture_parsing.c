/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:22:46 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/18 14:12:59 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	map_exist(char **input_tab2)
{
	int	tot;

	tot = count_map_related_lines(input_tab2);
	if (tot < 3)
		return (false);
	return (true);
}

bool	ft_doc_parsing(t_data *data)
{
	if (!map_exist(data->input_tab2))
		return (ft_printf("Error.\nNo map or map too small.\n"), false);
	if (!map_related_lines_all_together(data->input_tab2))
		return (ft_printf("Error.\nMap incorrect: lignes pas regroupees.\n"),
			false);
	if (!map_is_last(data->input_tab2))
	{
		return (ft_printf("Error.\nData not in order inside map file.\n"),
			false);
	}
	return (true);
}

/*strdup a partir de la pour avoir la string a essayer d ouvrir*/

int	get_rang(t_data *data, int i, int j)
{
	while (data->input_tab2[i][j])
	{
		if (!ft_iswhite_space(data->input_tab2[i][j]))
			break ;
		j++;
	}
	return (j);
}

char	*get_dir_str(t_data *data, char a, char b)
{
	int	i;
	int	j;
	int	verif;

	i = 0;
	verif = 0;
	while (data->input_tab2[i])
	{
		j = 0;
		while (data->input_tab2[i][j + 1])
		{
			if (data->input_tab2[i][j] == a && data->input_tab2[i][j + 1] == b)
			{
				verif = 1;
				j += 2;
				break ;
			}
			j++;
		}
		if (verif)
			break ;
		i++;
	}
	j = get_rang(data, i, j);
	return (ft_strdup(&data->input_tab2[i][j]));
}

// bool texture_check(t_data *data)
char	*get_color_str(t_data *data, char c)
{
	int	i;
	int	j;
	int	verif;

	i = 0;
	verif = 0;
	while (data->input_tab2[i])
	{
		j = 0;
		while (data->input_tab2[i][j + 1])
		{
			if (data->input_tab2[i][j] == c)
			{
				verif = 1;
				j++;
				break ;
			}
			j++;
		}
		if (verif)
			break ;
		i++;
	}
	j = get_rang(data, i, j);
	return (&data->input_tab2[i][j]);
}
