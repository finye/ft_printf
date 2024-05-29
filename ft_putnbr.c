/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:36:31 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/29 18:46:04 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num, int *count)
{
	long nbr;

	nbr = num;
	if (nbr < 0)
	{
		if(ft_putchar('-', count) == -1)
			return (-1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr /10 , count);
	}
	if (ft_putchar(nbr % 10 + '0', count) == -1)
		return (-1);
	return (*count);
}
