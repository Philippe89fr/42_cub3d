/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:01:13 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/19 15:15:13 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_printhexx(unsigned int nb, int k)
{
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	if (nb < 16)
	{
		if (hex[nb] <= 'z' && hex[nb] >= 'a')
		{
			c = ft_toupper(hex[nb]);
			write(1, &c, 1);
			k++;
		}
		else
		{
			write(1, &hex[nb], 1);
			k++;
		}
	}
	else
	{
		k = ft_printhexx(nb / 16, k);
		k = ft_printhexx(nb % 16, k);
	}
	return (k);
}
/*
int	main(void)
{
	unsigned int nb;

	nb = 3476;
	size_t a;
	a = ft_printheX(nb, 0);
	printf("\n%zu\n", a);
	return (0);
} */
