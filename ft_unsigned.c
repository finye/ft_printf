/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:32:24 by fsolomon          #+#    #+#             */
/*   Updated: 2024/06/07 16:13:16 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int num, int *count)
{
	if (num >= 10)
	{
		if (ft_unsigned(num / 10, count) == -1)
			return (-1);
	}
	if (ft_putchar(num % 10 + '0', count) == -1)
		return (-1);
	return (*count);
}