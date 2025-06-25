/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:51:25 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/11 18:02:33 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*b;

	i = ((j = ((k = 0))));
	b = ((char *)big);
	while (little[k])
		k++;
	if (!little[i])
		return (b);
	while (b[i] && i < len)
	{
		while (little[j] && big[i + j]
			&& big[i + j] == little[j] && (i + j) < len)
			j++;
		if (j == k)
			return (&b[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int	main(int ar, char **av)
{
	char	*res;
	char	*res1;

	ar = ar + 0;
	res = ft_strnstr(av[1], av[2], atoi(av[3]));
	res1 = strnstr(av[1], av[2], atoi(av[3]));
	printf("%s\n", res);
	printf("%s\n", res1);
	return (0); 
} */
