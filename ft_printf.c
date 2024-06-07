/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:40:44 by fsolomon          #+#    #+#             */
/*   Updated: 2024/06/07 16:08:31 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(va_list args, const char *str, int *count)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int), count));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *), count));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int), count));
	else if (*str == 'u')
		return (ft_unsigned(va_arg(args, unsigned int), count));
	else if (*str == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), count, -1));
	else if (*str == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), count, 1));
	else if (*str == 'p')
		return (ft_print_ptr((va_arg(args, void *)), count));
	else if (*str == '%')
		return (ft_putchar('%', count));
	return (-1);
}

static int	scan_str(va_list args, const char *str, int *count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
			{
				if (check_format(args, str++, count) == -1)
					return (-1);
			}
		}
		else if (ft_putchar(*str++, count) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	if (scan_str(args, str, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}