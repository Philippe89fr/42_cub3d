/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:55:50 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 09:46:39 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_len(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;
	int	res;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	k = j;
	while (ft_isset(s1[i], set))
		i++;
	if (i != j)
	{
		while (ft_isset(s1[k - 1], set))
			k--;
		res = j - i - (j - k);
		return (res);
	}
	return (0);
}

static char	*ft_malloc(char const *s1, char const *set)
{
	int		j;
	char	*tab;

	j = ft_len(s1, set);
	tab = (char *)malloc((j + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		i;
	int		j;
	int		k;

	i = ((k = ((j = 0))));
	while (s1[j])
		j++;
	tab = ft_malloc(s1, set);
	if (tab == NULL)
		return (NULL);
	while (ft_isset(s1[i], set))
		i++;
	while (ft_isset(s1[j - 1], set))
		j--;
	while (i + k < j && s1[i + k])
	{
		tab[k] = s1[i + k];
		k++;
	}
	tab[k] = '\0';
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	char	*tab;
	char const	*s1 = argv[1];
	char const	*set = argv[2];
	
	argc = argc + 0;
	tab = ft_strtrim(s1, set);
	printf("%d\n", ft_len(s1, set));
	printf("%s\n", tab);
	printf("%d\n", strcmp(tab, ""));
	free(tab);
	return (0);
} */
