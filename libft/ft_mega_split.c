/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mega_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:58:09 by prambaud          #+#    #+#             */
/*   Updated: 2025/03/04 10:59:18 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_ct_word(char *str, char *charset)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (!ft_sep(str[i - 1], charset) && ft_sep(str[i], charset))
			j++;
		i++;
	}
	if (!ft_sep(str[i - 1], charset))
		j++;
	return (j);
}

char	*ft_malloc(char *str, char *charset, int i)
{
	char	*tab;
	int		k;
	int		j;

	j = i;
	k = 0;
	while (str[i] && !ft_sep(str[i], charset))
		i++;
	tab = (char *)malloc((i + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (str[j] && !ft_sep(str[j], charset))
	{
		tab[k] = str[j];
		k++;
		j++;
	}
	tab[k] = '\0';
	return (tab);
}

char	**ft_mega_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		k;

	i = ((k = 0));
	tab = (char **)malloc((ft_ct_word(str, charset) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[ft_ct_word(str, charset)] = 0;
	while (str[i])
	{
		if ((i > 0) && (!ft_sep(str[i], charset) && (ft_sep(str[i - 1],
						charset))))
		{
			tab[k] = ft_malloc(str, charset, i);
			k++;
		}
		if ((i == 0) && (!ft_sep(str[i], charset)))
		{
			tab[k] = ft_malloc(str, charset, i);
			k++;
		}
		i++;
	}
	return (tab);
}

// int	main(int argc, char **argv)
// {
// 	int	i;
// 	char	**tab;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (argc < 2)
// 		return (0);
// //	printf("Count word: %d\n", ft_ct_word(argv[1], argv[2]));
// 	tab = ft_split(argv[1], argv[2]);
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	} /*
// 	while (tab[j])
// 	{
// 		free(tab[j]);
// 		j++;
// 	}
// 	free(tab); */
// 	return (0);
// }