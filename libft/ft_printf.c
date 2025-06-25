/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:51:33 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/11 12:13:39 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	static	ft_printnext(const char *s)
{
	int	n;

	n = 2;
	write(1, "%", 1);
	write(1, s, 1);
	return (n);
}

int	static	ft_print2(va_list l, const char *s)
{
	int		n;

	n = 1;
	if (*s == 'c')
		ft_putchar((char)va_arg(l, int));
	else if (*s == '%')
		write(1, "%", 1);
	else if (*s == 's')
		n = ft_putstr(va_arg(l, char *));
	else if (*s == 'd' || *s == 'i')
		n = ft_putnbr(va_arg(l, int), 0);
	else if (*s == 'x')
		n = ft_printhex(va_arg(l, int), 0);
	else if (*s == 'u')
		n = ft_putnbru(va_arg(l, unsigned int), 0);
	else if (*s == 'p')
		n = ft_printpointer(va_arg(l, void *));
	else if (*s == 'X')
		n = ft_printhexx(va_arg(l, int), 0);
	else
		n = ft_printnext(s);
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	l;
	int		tot;
	int		len;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	va_start(l, s);
	tot = ((i = 0));
	while (s[i])
	{
		if (s[i] == '%')
		{
			tot = tot + ft_print2(l, &s[i + 1]);
			i = i + 2;
		}
		else if (s[i] != '%')
		{
			write(1, &s[i++], 1);
			tot++;
		}	
	}
	va_end(l);
	return (tot);
}
/*
int	main(int ac, char **av)
{
	char	ch;
	int		a;
	int		b;
	int		i;
	char	*str;
	int		c;
	int		d;
	int		e;
	int		f;

	a = (( b = (( c = 0))));
	d = (( e = (( f = 0))));
	ac = ac + 0;
	str = av[1];
	i = atoi(av[2]);
	ch = av[3][0];
	//ft_printf(" %p %p ", 0, 0);
	//printf(" %p %p ", 0, 0);
	a = ft_printf("My name is %s, %d years old, fav letter is %c\n", str, i, ch);
	b = printf("My name is %s, %d years old, fav letter is %c\n", str, i, ch);
	c = ft_printf("Hex is %x, heX is %X, '%%' gives %%\n", i, i);
	d = printf("Hex is %x, heX is %X, '%%' gives %%\n",i, i);
	e = ft_printf("U is %u, pointer is %p\n", i, &i);
	f = printf("U is %u, pointer is %p\n", i, &i);
	write(1, "\n", 1);
	printf("\nft_printf = %d et printf = %d\n", a, b);
	printf("\nft_printf = %d et printf = %d\n", c, d);
	printf("\nft_printf = %d et printf = %d\n", e, f);
	printf("\n%d\n", ft_printf("Unsigned is %u", i));
	printf("\n%d\n", printf("Unsigned is %u", i));
	printf("\n%d\n", ft_printf("Char is %c", c));
	printf("\n%d\n", printf("Char is %c", c)); 
	return (0); 
} */
