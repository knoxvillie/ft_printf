/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:48:09 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/01 16:45:04 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int static	ft_mainprintf(char specifier, va_list var)
{
	if (specifier == '%')
		write(1, "%", 1);
	else if (specifier == 'c')
		ft_printfc(va_arg(var, int));
	else if (specifier == 's')
		ft_printfs(va_arg(var, char *));
	else if (specifier == 'i' || specifier == 'd')
		ft_printfd(va_arg(var, int));
	else if (specifier == 'u')
		ft_printfu(va_arg(var, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		ft_printfx(va_arg(var, unsigned int), specifier);
	else if (specifier == 'p')
		ft_printfp(va_arg(var, unsigned long));
}

int ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	var;

	va_start(var, str);
	i = 0;
	count = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_checkspecifier(*(str + i)))
			ft_mainprintf((str + i), var);
		else if (*(str + i) == '%' && !ft_checkspecifier(*(str + i)))
			write (1, "Especifier ERROR!", 18);
		else
			write (1, (str + i), 1);
		i++;
	}
}
