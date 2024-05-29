/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:40:44 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/29 19:11:56 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_format(va_list args, const char *str, int *count)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int), count));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char*), count));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int), count));
	else if (*str == 'u')
		return (ft_unsigned(va_arg(args, unsigned int), count));
	return (-1);
}
static int scan_str(va_list args, const char *str, int *count)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (check_format(args, str, count) == -1)
				return (-1);
		}
		else if (ft_putchar(*str, count) == -1)
			return (-1);
		str++;
	}
	return (0);
}
int    ft_printf(const char *str, ...)
 {
	int	count;
	va_list args;
	
	va_start(args, str);
	count = 0;
	if(scan_str(args, str, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
 }

int main (void)
{
	int r1, r2, r3, r4, r5, r6 = 0;
	
	char *s1 = 0;
	r1 = printf("%s \n", s1);
	r2 = ft_printf("%s \n", s1);

	r3 = printf("%d \n", -2147483648);
	r4 = ft_printf("%d \n", -2147483648);
	
	r5 = printf("%u \n", 4294967295);
	r6 = printf("%u \n", 4294967295);
	
	printf("%d \n%d \n%d \n%d \n%u \n%u ", r1, r2 , r3, r4 , r5, r6);	
}