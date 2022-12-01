/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:04:24 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/01 17:05:32 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_get_num_len(long long num, int base)
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

void	ft_printfx(unsigned int num, char c)
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
