/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:36:31 by fsolomon          #+#    #+#             */
/*   Updated: 2024/06/07 16:12:26 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num, int *count)
{
	if (num == -2147483648)
	{
		if (ft_putstr("-2147483648", count) == -1)
			return (-1);
		return (*count);
	}
	if (num < 0)
	{
		if (ft_putchar('-', count) == -1)
			return (-1);
		num *= -1;
	}
	if (num >= 10)
	{
		if (ft_putnbr(num / 10, count) == -1)
			return (-1);
	}
	if (ft_putchar(num % 10 + '0', count) == -1)
		return (-1);
	return (*count);
}
