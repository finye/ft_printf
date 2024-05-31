/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:40:44 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/31 17:22:34 by fsolomon         ###   ########.fr       */
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
	else if (*str == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), count, 0));
	else if (*str == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), count, 1));
	else if (*str == 'p')
		return (ft_print_ptr(((unsigned long int)va_arg(args, void *)), count));
	else if (*str == '%')
		return (ft_putchar('%', count));
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

/* int main (void)
{
	int r1, r2, r3, r4, r5, r6= 0;
	int r7, r8 = 0;
	
	char *s1 = NULL;
	r1 = printf("%s \n", s1);
	r2 = ft_printf("%s \n", s1);

	r3 = printf("%d \n", -2147483648);
	r4 = ft_printf("%d \n", -2147483648);
	
	r5 = printf("%u \n", 4294967295);
	r6 = ft_printf("%u \n", 4294967295);
	
	r7 = printf("%x \n", 10);
	r8 = ft_printf("%x \n", 10);

	printf("%x%x%x%x%x \n", 1, 100, 999, 42, 999988888);
	ft_printf("%x%x%x%x%x \n", 1, 100, 999, 42, 999988888);
	
	printf("%d \n%d \n%d \n%d \n%d \n%d \n%d \n%d", r1, r2 , r3, r4 , r5, r6, r7, r8);	

}   */