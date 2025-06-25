/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:28:10 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/12 10:28:21 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;	

	if (nmemb == 0 || size == 0)
	{
		tab = malloc(0);
		if (tab == NULL)
			return (NULL);
		return (tab);
	}
	if (nmemb * size > 2147483647)
		return (NULL);
	tab = (void *)malloc((nmemb) * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
/*
int	main(void)
{
	char	*tab;
	char	*tab2;

	tab = ft_calloc(30, 1);
	write(1, tab, 30);
	write(1, "\n", 1);
	tab2 = calloc(30, 1);
	write(1, tab2, 30);
	return (0);
} */
