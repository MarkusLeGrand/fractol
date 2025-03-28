/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:40:08 by lkantzer          #+#    #+#             */
/*   Updated: 2024/12/09 13:40:08 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	if (uppercase)
		return (ft_print_number_base(n, "0123456789ABCDEF"));
	else
		return (ft_print_number_base(n, "0123456789abcdef"));
}
