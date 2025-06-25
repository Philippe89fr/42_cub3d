/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:44:02 by vincent           #+#    #+#             */
/*   Updated: 2025/03/17 18:34:03 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "cub3d.h"

void	welcome_message(void)
{
	ft_printf(GREEN "\n");
	printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░░░█▀▀░█▀█░█▀█░▀█▀░█▀▄░█▀█░█░░░█▀▀\n");
	printf("░█░░░█░█░█▀▄░░▀▄░█░█░░░█░░░█░█░█░█░░█░░█▀▄░█░█░█░░░▀▀█\n");
	printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░░░▀▀▀░▀▀▀░▀░▀░░▀░░▀░▀░▀▀▀░▀▀▀░▀▀▀\n");
	printf(RESET "\n");
	printf(GREEN "\tW" RESET ": move forward\t");
	printf(GREEN "\tS" RESET ": move backward\n");
	printf(GREEN "\tA" RESET ": strafe left\t");
	printf(GREEN "\tD" RESET ": strafe right\n");
	printf(GREEN "\t<" RESET ": rotate left\t");
	printf(GREEN "\t>" RESET ": rotate right\n");
	printf("\n");
}

bool	map_name_verif(char *input_file)
{
	int	i;

	i = 0;
	if (access(input_file, R_OK) == -1)
		return (false);
	while (input_file[i])
		i++;
	if (i - 1 < 0 || input_file[i - 1] != 'b')
		return (false);
	if (i - 2 < 0 || input_file[i - 2] != 'u')
		return (false);
	if (i - 3 < 0 || input_file[i - 3] != 'c')
		return (false);
	if (i - 4 < 0 || input_file[i - 4] != '.')
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("wrong input"), 0);
	data.ac = ac;
	data.av = av;
	data.input_file = av[1];
	if (!map_name_verif(data.input_file))
		return (ft_printf("Error.\nMap file invalid.\n"), 1);
	if (ft_init_struct(&data))
	{
		welcome_message();
		start_game(&data);
	}
	liberator_god(&data);
	return (0);
}
