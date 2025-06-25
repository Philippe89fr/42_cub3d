/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:48 by lbenatar          #+#    #+#             */
/*   Updated: 2025/03/04 12:24:10 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 16)
		i++;
	if (n >= 16)
	{
		i++;
		i += ft_size_hex(n / 16);
	}
	return (i);
}

static void	fill_hex(unsigned int n, int i, char *num, char *hex)
{
	while (n > 15)
	{
		num[i] = hex[n % 16];
		n = n / 16;
		i--;
	}
	num[i] = hex[n % 16];
}

char	*ft_int_hex(unsigned int n)
{
	char	*num;
	char	*hex;
	int		i;

	if (n < 0)
		n = (4294967295 + n + 1);
	hex = "0123456789abcdef";
	num = (char *)malloc((ft_size_hex(n) + 1) * sizeof(char));
	if (!num)
		return (NULL);
	i = ft_size_hex(n);
	num[i] = '\0';
	i--;
	fill_hex(n, i, num, hex);
	return (num);
}
