/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:32:24 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/29 19:16:23 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int num, int *count)
{
	if (num >= 10)
	{
		ft_unsigned(num /10, count);
	}
	if (ft_putchar(num % 10 + '0', count) == -1)
		return (-1);
	return (*count);
}