/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:28:25 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/17 17:43:47 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

bool	ft_3_positive_number(t_data *data)
{
	int	i;
	int	len;

	len = ft_strlen_dim2((const char **)data->color_c);
	i = 0;
	if (len != 3)
		return (false);
	while (data->color_c[i])
	{
		if (ft_atoi(data->color_c[i]) < 0)
			return (false);
		i++;
	}
	len = ft_strlen_dim2((const char **)data->color_f);
	i = 0;
	if (len != 3)
		return (false);
	while (data->color_f[i])
	{
		if (ft_atoi(data->color_f[i]) < 0)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_parsing_color(t_data *data)
{
	if (!ft_3_positive_number(data))
		return (false);
	return (true);
}
