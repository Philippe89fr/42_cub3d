/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:08:23 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 10:23:41 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (src >= dest)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
int	main(int ar, char **av)
{
	char	*c;
	char	*c1;

	c = malloc(10);
	c1 = malloc(10);
	ar = ar + 0;
	printf("%s\n", (char *)ft_memmove(((void *)NULL), av[1], atoi(av[2])));	
	printf("%s\n", (char *)memmove(((void *)NULL), av[1], atoi(av[2])));
	return (0);	
} */
