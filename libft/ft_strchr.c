/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:22:26 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/11 18:08:18 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = 0;
	d = ((char *)s);
	while (d[i] && d[i] != (unsigned char)c)
		i++;
	if (d[i] == (unsigned char)c)
		return (&d[i]);
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	char	*d;

	ac = ac + 0;
	d = ft_strchr(av[1], av[1][0] + 256);
	printf("%s\n", d);
	printf("%s\n", strchr(av[1], av[1][0] + 256));
	return (0);
} */
