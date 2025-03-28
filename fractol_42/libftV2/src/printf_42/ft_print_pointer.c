/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:48:49 by lkantzer          #+#    #+#             */
/*   Updated: 2024/12/09 13:48:49 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	ft_puthex(unsigned long num)
{
	if (num >= 16)
		ft_puthex(num / 16);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

static int	ft_hex_len(unsigned long num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	int	len;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	len = 2;
	ft_puthex((unsigned long)ptr);
	len += ft_hex_len((unsigned long)ptr);
	return (len);
}
