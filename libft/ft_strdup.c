/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:11:18 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/08 18:17:32 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	tab = (char *)malloc((i + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s[j])
	{
		tab[j] = s[j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
/*
int	main(void)
{
	char	*s;
	char	*b;

	s = "test";
	b = ft_strdup(s);
	printf("%s\n", b);
	return (0);
} */
