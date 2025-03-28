/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:51:19 by lkantzer          #+#    #+#             */
/*   Updated: 2024/12/09 13:51:19 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	handle_format(const char *format, va_list args);
int	handle_conversion(char specifier, va_list args);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_pointer(void *ptr);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, int uppercase);
int	ft_print_number_base(unsigned long long n, const char *base);

#endif
