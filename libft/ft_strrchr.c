/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:45:11 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/11 17:01:10 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = 0;
	d = ((char *)s);
	while (d[i])
		i++;
	while (i >= 0)
	{
		if (d[i] == (unsigned char )c)
			return (&d[i]);
		i--;
	}
	return (NULL);
}
/*
int main(int ar, char **av)
{
    char    *s = av[1];
    char    *d;
    char    *e;

	if (ar != 3)
		return (0);
    d = ft_strrchr(s, av[2][0]);
    e = strrchr(s, av[2][0]);
    printf("%s\n", d);
    printf("%s\n", e);
    return (0);
} */
