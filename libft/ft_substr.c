/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:50:10 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 10:15:52 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	t;

	t = ft_strlen(s);
	j = 0;
	while ((start + j) < t && j < len)
		j++;
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	t;

	t = ft_strlen(s);
	i = 0;
	if (start > t)
	{
		tab = (char *)malloc((1) * sizeof(char));
		if (tab == 0)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	tab = (char *)malloc((ft_size(s, start, len) + 1) * sizeof(char));
	if (tab == 0)
		return (NULL);
	while (start + i < t && i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
int	main(void)
{
	char	*s = "";
	char	*d;
	int	i;

	d = ft_substr(s, 1, 1);
	i = strcmp(d, "");	
	printf("%s\n", d);
	printf("%d\n", i);
	free(d);
	return (0);
} */
