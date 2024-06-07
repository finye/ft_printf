/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:31:47 by fsolomon          #+#    #+#             */
/*   Updated: 2024/06/07 16:12:49 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int *count)
{
	if (!str)
	{
		if (ft_putstr("(null)", count) == -1)
			return (-1);
		return (*count);
	}
	while (*str)
	{
		if (ft_putchar(*str, count) == -1)
			return (-1);
		str++;
	}
	return (*count);
}