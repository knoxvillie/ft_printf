/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:16:07 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/01 14:23:51 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void ft_printfc(char c)
{
	write(1, &c, 1);
}

void ft_printfs(char *str)
{
	int i;

	i = 0;
	while (str && *(str + i))
	{
		write(1, (str + i), 1);
		i++;
	}
}

void ft_printfd(int num)
{
	long n;

	n = num;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 0 && n <= 9)
	{
		ft_printfc(n + '0');
	}
	else
	{
		ft_printfd(n / 10);
		ft_printfd(n % 10);
	}
}

void ft_printfu(unsigned int num)
{

	if (num >= 0 && num <= 9)
	{
		ft_printfc(num + '0');
	}
	else
	{
		ft_printfd(num / 10);
		ft_printfd(num % 10);
	}
}
int ft_get_num_len(long long num, int base)
{
	int len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

void ft_printfx(unsigned int num, char c)
{
	int 	len;
	char 	*str;
	char	*basehex;

	if (c == 'x')
		basehex = "0123456789abcdef";
	else
		basehex = "0123456789ABCDEF";
	len = ft_get_num_len(num, 16);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	*(str + len--) = '\0';
	while (len >= 0)
	{
		*(str + len) = *(basehex + (num % 16));
		num /= 16;
		len--;
	}
	ft_printfs(str);
}

void	ft_printfp(unsigned long num)
{
	int				len;
	char			*str;
	unsigned long 	n;

	n = num;
	len = 0;
	if (num == 0)
		len = 1;
	while (n > 0 && len++ >= 0)
		n /= 16;
	len += 2;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	*(str + len) = '\0';
	*(str + 0) = '0';
	*(str + 1) = 'x';
	while (len > 1)
	{
		*(str + len) = "0123456789abcdef"[num % 16];
		num /= 16;
		len--;
	}
	ft_printfs(str);
}

char ft_checkspecifier(char xar)
{
	char *specifier;
	int i;

	i = 0;
	specifier = "cspdiuxX%";
	while (*(specifier + i))
	{
		if (xar == *(specifier + i))
			return (*(specifier + i));
		i++;
	}
	return (0);
}

int ft_printf(const char *str, ...)
{
	char specifier;
	int i;
	va_list var;

	va_start(var, str);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_checkspecifier(*(str + i + 1)))
		{
			i++;
			specifier = ft_checkspecifier(*(str + i));
			if (specifier == '%')
			{
				write(1, "%", 1);
			}
			else if (specifier == 'c')
			{
				ft_printfc(va_arg(var, int));
			}
			else if (specifier == 's')
			{
				ft_printfs(va_arg(var, char *));
			}
			else if (specifier == 'i' || specifier == 'd')
			{
				ft_printfd(va_arg(var, int));
			}
			else if (specifier == 'u')
			{
				ft_printfu(va_arg(var, unsigned int));
			}
			else if (specifier == 'x' || specifier == 'X')
			{
				ft_printfx(va_arg(var, unsigned int), specifier);
			}
			else if (specifier == 'p')
				ft_printfp(va_arg(var, unsigned long));
			i++;
		}
		else if (*(str + i) == '%' && !(ft_checkspecifier(*(str + i + 1))))
		{
			write(1, "ANIMAL", 6);
			return (0);
		}
		else
			write(1, (str + i++), 1);
	}
	va_end(var);
	return (i);
}

int main(int argc, char **argv)
{
	char c;
	int a;
	int b;
	unsigned int k;
	int	x;
	char	*y;

	y = "hello";
	x = 0x4fa;
	k = 5556667;
	a = 2147483647;
	b = -2147483648;
	c = '@';

	if (argc < 2)
		return (0);
	ft_printf(*(argv + 1), y);
	return (0);
}
