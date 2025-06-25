/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:53:59 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/14 14:47:56 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	ft_up(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char	*s = strdup("aaa");
	
	ft_striteri(s, ft_up);
	printf("%s\n", s);
	return (0);
} */
