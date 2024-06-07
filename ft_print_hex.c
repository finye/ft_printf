/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:40:58 by fsolomon          #+#    #+#             */
/*   Updated: 2024/06/07 16:06:40 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, int *count, int is_upper_case)
{
	char	*upper_digits;
	char	*lower_digits;
	char	*digits;

	upper_digits = "0123456789ABCDEF";
	lower_digits = "0123456789abcdef";
	if (is_upper_case == 1)
		digits = upper_digits;
	else
		digits = lower_digits;
	if (num >= 16)
	{
		if (ft_print_hex(num / 16, count, is_upper_case) == -1)
			return (-1);
	}
	if (ft_putchar(digits[num % 16], count) == -1)
		return (-1);
	return (*count);
}
