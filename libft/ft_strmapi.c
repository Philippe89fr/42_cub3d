/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:34:59 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 14:19:08 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	while (s[j])
		j++;
	tab = (char *)malloc((j + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
static char	ft_up(unsigned int i, char c)
{
	char	r;

	r = c + i;
	return (r);
}

int	main(void)
{
	char	*tab;
	char	*s = "aaa";
	
	tab = ft_strmapi(s, ft_up);
	printf("%s\n", tab);
	return (0);
} */
