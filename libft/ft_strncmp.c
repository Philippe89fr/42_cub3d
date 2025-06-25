/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:50:24 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/11 09:33:25 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (i == n)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(int ar, char **av)
{
	char	*s1;
	char	*s2;

	if (ar < 2)
		return (0);
	s1 = av[1];
	s2 = av[2];
	printf("%d\n", ft_strncmp(s1, s2, atoi(av[3])));
	printf("%d\n", strncmp(s1, s2, atoi(av[3])));
	return (0);
} */	
