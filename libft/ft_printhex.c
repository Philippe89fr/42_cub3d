/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:01:13 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/19 15:15:14 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_printhex(unsigned int nb, int k)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb < 16)
	{
		write(1, &hex[nb], 1);
		k++;
	}
	else
	{
		k = ft_printhex(nb / 16, k);
		k = ft_printhex(nb % 16, k);
	}
	return (k);
}
/*
int	main(void)
{
	unsigned int nb;

	nb = 3476;
	size_t a;
	a = ft_printhex(nb, 0);
	printf("\n%zu\n", a);
	return (0);
} */
