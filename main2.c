/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:20 by kfaustin          #+#    #+#             */
/*   Updated: 2022/12/05 16:31:25 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// char	*str = "Hello Uord";
	// char	*str2 = "PRINTF: %s%d\n";
	int		p1;
	int		p2;


	p2 = ft_printf("_%p ", 17);
	printf("Retorno: %d\n", p2);
	p1 = printf("_%p ", 17);
	printf("Retorno: %d\n", p1);

	return (0);
}
