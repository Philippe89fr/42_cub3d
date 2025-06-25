/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:34:28 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/19 15:15:12 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_putnbr(int nb, int k)
{
	long int	i;

	i = nb;
	if (i < 0)
	{
		write(1, "-", 1);
		i = i * (-1);
		k++;
	}
	if (i <= 9 && i >= 0)
	{
		i = i + '0';
		write(1, &i, 1);
		k++;
	}
	else
	{
		k = ft_putnbr(i / 10, k);
		k = ft_putnbr(i % 10, k);
	}
	return (k);
}
/*
int	main(int argc, char **argv)
{
	ft_putnbr(atoi(argv[1]));
//	int	i;
	
//	i = -2147483648;
//	ft_putnbr(i);
	return (0);
} */
