/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:00:00 by lkantzer          #+#    #+#             */
/*   Updated: 2024/12/05 17:30:00 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_print_number_base(unsigned long long n, const char *base)
{
	char	buffer[50];
	int		base_len;
	int		i;

	base_len = ft_strlen(base);
	i = 49;
	buffer[i--] = '\0';
	if (n == 0)
		buffer[i--] = base[0];
	while (n > 0)
	{
		buffer[i--] = base[n % base_len];
		n /= base_len;
	}
	return (write(1, &buffer[i + 1], ft_strlen(&buffer[i + 1])));
}
