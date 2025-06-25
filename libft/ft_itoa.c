/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:30:50 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/14 14:46:57 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_ct_numbers(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char	*ft_putnbr_tab(char *tab, long int nb)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (nb < 0)
	{
		tab[i] = '-';
		tab[i + 1] = '\0';
		nb = -nb;
		i++;
	}
	if (nb <= 9)
	{
		tab[i] = nb + '0';
		tab[i + 1] = '\0';
		i++;
	}
	if (nb > 9)
	{
		ft_putnbr_tab(tab, nb / 10);
		ft_putnbr_tab(tab, nb % 10);
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			i;
	long int	nb;

	nb = n;
	i = ft_ct_numbers(nb);
	if (nb < 0)
	{
		tab = (char *)malloc(i + 2 * sizeof(char));
		if (tab == NULL)
			return (NULL);
	}
	if (nb >= 0)
	{
		tab = (char *)malloc(i + 1 * sizeof(char));
		if (tab == NULL)
			return (NULL);
	}
	tab[0] = '\0';
	tab = ft_putnbr_tab(tab, nb);
	return (tab);
}
/*
int	main(void)
{
	int	i;
	int j;
	i = -1000;
	char *tab;
	
	j = 0;
	tab = ft_itoa(i);
//	printf("%d\n",ft_ct_numbers(i));
	printf("%s\n", tab);
	return (0);
} */
