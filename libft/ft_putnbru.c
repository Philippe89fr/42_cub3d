/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:34:28 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/19 15:15:12 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_putnbru(int unsigned nb, int k)
{
	unsigned long int	i;

	i = nb;
	if (i <= 9 && i >= 0)
	{
		i = i + '0';
		write(1, &i, 1);
		k++;
	}
	else
	{
		k = ft_putnbru(i / 10, k);
		k = ft_putnbru(i % 10, k);
	}
	return (k);
}
/*
int	main(int argc, char **argv)
{
	unsigned int	i;

	argc = argc + 0;	
	i = 2147483648;
	printf("\n%u\n",ft_putnbru(atoi(argv[1]), 0));
	return (0);
} */
