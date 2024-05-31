/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:37:02 by fsolomon          #+#    #+#             */
/*   Updated: 2024/05/31 17:21:39 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//remove later!!!
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c, int *count);
int ft_putstr(char *str, int *count);
int	ft_putnbr(int num, int *count);
int	ft_unsigned(unsigned int num, int *count);
int	ft_print_hex(unsigned int num, int *count, int text_case);
int ft_print_ptr(unsigned long int ptr, int *count);

#endif