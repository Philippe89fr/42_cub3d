/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:12:29 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/09 16:43:49 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 122 && c >= 97)
		c = c - 32;
	return (c);
}
/*
int	main(void)
{
	int c;

	c = 'b';
	ft_toupper(c);
	printf("%c\n", c);
	return (0);
} */
