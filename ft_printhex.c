/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:57:53 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/30 18:18:34 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hex(unsigned int num, int *count, int text_case)
{
	char *symbol;

	if (text_case == 0)
		symbol = "0123456789abcdef";
	else if (text_case == 1)
		symbol = "0123456789ABCDEF";
	if (num >= 16)
	{
		ft_print_hex(num / 16, count, text_case);
	}
	ft_putchar(symbol[num % 16], count);
	return (*count);
}
