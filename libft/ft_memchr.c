/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:06:05 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 09:14:00 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = ((unsigned char *)s);
	if (d[0] == '\0' && n != 0 && c == '\0')
		return (d);
	while (i < n)
	{
		if (d[i] == (unsigned char)c)
			return (&d[i]);
		i++;
	}
	return (NULL);
}
/*
int main(int ar, char **av)
{
	ar = ar + 0;
	printf("%s\n", (char *)ft_memchr(av[1], av[2][0], atoi(av[3])));
	printf("%s\n", (char *)memchr(av[1], av[2][0], atoi(av[3])));
    return (0);
}*/
