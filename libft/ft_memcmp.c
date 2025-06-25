/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:09:24 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/11 16:19:11 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	if (!s2 && !s1)
		return (0);
	a = ((unsigned char *)s1);
	b = ((unsigned char *)s2);
	if (n == 0)
		return (0);
	while (b[i] == a[i] && i < n - 1)
		i++;
	return (a[i] - b[i]);
}
/*
int main(int ac, char **av)
{
    ac = ac + 0;

    printf("%d\n", ft_memcmp(av[1], av[2], atoi(av[3])));
    printf("%d\n", memcmp(av[1], av[2], atoi(av[3])));
    return (0);
} */
