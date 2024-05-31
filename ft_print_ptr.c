/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:52:06 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/31 17:26:41 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ptr(unsigned long int ptr, int *count)
{
	if (ptr == 0)
		{
			if (ft_putstr("0x0", count) == -1)
				return (-1);
		}
	else
	{
		if (ft_putstr("0x", count) == -1)
			return (-1);
		if(ft_print_hex(ptr, count, 0) == -1)
			return (-1);
	}
	return (0);
}