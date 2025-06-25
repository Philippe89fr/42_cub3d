/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:30:50 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/11 12:13:51 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

static int	ft_ct_numbers(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

static char	*ft_putnbr_tab_hex(char *tab, unsigned long long nb)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (tab[i])
		i++;
	if (nb <= 15)
	{
		tab[i] = hex[nb];
		tab[i + 1] = '\0';
		i++;
	}
	if (nb > 15)
	{
		ft_putnbr_tab_hex(tab, nb / 16);
		ft_putnbr_tab_hex(tab, nb % 16);
	}
	return (tab);
}

static char	*ft_itoahex(void *p)
{
	char				*tab;
	int					i;
	unsigned long long	nb;

	nb = (unsigned long long)p;
	i = ft_ct_numbers(nb);
	tab = (char *)malloc(i + 1 * sizeof(char));
	if (tab == NULL)
		return (NULL);
	tab[0] = '\0';
	tab = ft_putnbr_tab_hex(tab, nb);
	return (tab);
}

int	ft_printpointer(void *p)
{
	unsigned long long	n;
	char				*str;

	if (p == NULL)
	{
		str = "(nil)";
		write(1, "(nil)", 5);
		n = 5;
	}
	else
	{
		str = ft_itoahex(p);
		write(1, "0x", 2);
		n = ft_putstr(str);
		free(str);
		n = n + 2;
	}
	return (n);
}
/*
int	main(void)
{
	void	*i;
	size_t	j;
	i = 0;
	char *tab;
	
	j = 0;
	tab = ft_itoahex(i);
	printf("Le vrai: %p\n", i);
	j = ft_printpointer(i);
//	printf("%d\n",ft_ct_numbers(i));
//	printf("\n%d\n", (int)j);
	return (0);
} */
