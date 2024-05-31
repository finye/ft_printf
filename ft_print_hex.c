/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:40:58 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/31 17:28:54 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	ft_print_hex(unsigned int num, int *count, int text_case)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (num >= 16)
		 ft_print_hex(num / 16, count, text_case);
	else 
	{
		if (text_case == 0)
		{
			if (ft_putchar(lower_digits[num % 16], count) == -1)
				return (-1);
		}
		if (text_case == 1)
			{
			if (ft_putchar(upper_digits[num % 16], count) == -1)
				return (-1);
		}
	}

	return (*count);
} */

/* int	ft_print_hex(unsigned int num, int *count, int text_case)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (num < 16)
	{
		if (text_case == 0)
		{
			if (ft_putchar(lower_digits[num % 16], count) == -1)
				return (-1);
		}
		if (text_case == 1)
			{
			if (ft_putchar(upper_digits[num % 16], count) == -1)
				return (-1);
		}
	}
	else
		ft_print_hex(num / 16, count, text_case);
		
	return (*count);
} */

int ft_print_hex(unsigned int num, int *count, int is_upper_case)
{
    static char upper_digits[] = "0123456789ABCDEF";
    static char lower_digits[] = "0123456789abcdef";
    char *digits;

    if (is_upper_case)
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
