/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:37:32 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/08 18:23:06 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	j = ft_strlen(src);
	k = ft_strlen(dst);
	if (siz <= k)
		return (j + siz);
	while ((i + k < siz - 1) && src[i])
	{
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = '\0';
	return (j + k);
}
