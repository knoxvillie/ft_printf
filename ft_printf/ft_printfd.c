/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:57:08 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/01 16:58:52 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_printfd(int num)
{
	long number;

	number = num;
	if (number == -2147483648)
	{
		write(1, "-2", 2);
		number = 147483648;
	}
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number >= 0 && number <= 9)
	{
		ft_printfc(number + '0');
	}
	else
	{
		ft_printfd(number / 10);
		ft_printfd(number % 10);
	}
}
