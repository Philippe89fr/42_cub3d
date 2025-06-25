/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:21:50 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 09:41:22 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc(char *s1, char *s2)
{
	int		j;
	char	*tab;

	j = ft_strlen(s1) + ft_strlen(s2);
	tab = (char *)malloc((j + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s4;
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = ((char *)s1);
	s4 = ((char *)s2);
	tab = ft_malloc(s3, s4);
	if (tab == NULL)
		return (NULL);
	while (s3[i])
	{
		tab[i] = s3[i];
		i++;
	}
	while (s4[j])
	{
		tab[i + j] = s4[j];
		j++;
	}
	tab [i + j] = '\0';
	return (tab);
}
/*
int	main(void)
{
	char const	*s1 = "coucou";
	char const	*s2 = ", ca va?";
	char	*tab;

	tab = ft_strjoin(s1, s2);
	printf("%s\n", tab);
	return (0);
} */
