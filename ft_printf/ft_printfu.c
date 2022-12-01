/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:00:27 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/01 17:01:58 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
