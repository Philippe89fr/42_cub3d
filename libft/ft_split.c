/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:15:36 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 11:27:24 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_liberator(char **tab, int k)
{
	int	i;

	i = 0;
	while (i <= k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_ct_word(char const *str, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if ((str[i - 1] != c) && (str[i] == c))
			j++;
		i++;
	}
	if (str[i - 1] != c)
		j++;
	return (j);
}

static char	*ft_malloc(char const *str, char c, int i)
{
	char		*tab;
	int			k;
	int			j;

	j = i;
	k = 0;
	while (str[i] && (str[i] != c))
		i++;
	tab = (char *)malloc((i - j + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (str[j] && (str[j] != c))
	{
		tab[k] = str[j];
		k++;
		j++;
	}
	tab[k] = '\0';
	return (tab);
}

static int	ft_loopmalloc(char **tab, int k, char *mall)
{
	tab[k] = mall;
	if (!tab[k])
	{
		ft_liberator(tab, k);
		return (-1);
	}
	k++;
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	i = ((k = 0));
	tab = (char **)malloc((ft_ct_word(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[ft_ct_word(s, c)] = 0;
	while (s[i])
	{
		if ((i > 0) && (s[i] != c) && (s[i - 1] == c))
			k = ft_loopmalloc(tab, k, ft_malloc(s, c, i));
		else if ((i == 0) && (s[i] != c))
			k = ft_loopmalloc(tab, k, ft_malloc(s, c, i));
		if (k == -1)
			return (NULL);
		i++;
	}
	return (tab);
}
/*
La fonction ft_loopmalloc( existe a cause de la norminette
*/

/*
int	main(int argc, char **argv)
{
	int	i;
	char	**tab;
	int	j;
	char	c;

	c = argv[2][0];
	i = 0;
	j = 0;
	if (argc < 2)
		return (0);
	printf("Count word: %d\n", ft_ct_word(argv[1], c));
	tab = ft_split(argv[1], c);
//	tab = split(argv[1], c);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	} 
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab); 
	return (0); 
} */
