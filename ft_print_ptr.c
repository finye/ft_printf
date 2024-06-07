/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:52:06 by fsolomon          #+#    #+#             */
/*   Updated: 2024/06/07 16:07:05 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	ft_hex(unsigned long num, int *count)
{
	char	*lower_digits;

	lower_digits = "0123456789abcdef";
	if (num >= 16)
	{
		if (ft_hex(num / 16, count) == -1)
			return (-1);
	}
	if (ft_putchar(lower_digits[num % 16], count) == -1)
		return (-1);
	return (*count);
}

int	ft_print_ptr(void *ptr, int *count)
{
	unsigned long	ptr_val;

	if (ptr == 0)
	{
		if (ft_putstr("0x0", count) == -1)
			return (-1);
	}
	else
	{
		ptr_val = (unsigned long)ptr;
		if (ft_putstr("0x", count) == -1)
			return (-1);
		if (ft_hex(ptr_val, count) == -1)
			return (-1);
	}
	return (0);
}