/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:27:38 by prambaud          #+#    #+#             */
/*   Updated: 2024/11/11 17:26:17 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (fd < 0)
		return ;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = i * (-1);
	}
	if (i <= 9 && i >= 0)
	{
		i = i + '0';
		write(fd, &i, 1);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT);
	if (fd == -1)
		return (1);
	ft_putnbr_fd(-44, fd);	
	return (0);
} */
