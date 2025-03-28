/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:56:28 by lkantzer          #+#    #+#             */
/*   Updated: 2025/02/16 16:01:32 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double zr, double zi, t_data *data)
{
	double	tmp;
	int		i;

	i = 0;
	while ((zr * zr + zi * zi) <= 4.0 && i < data->max_iter)
	{
		tmp = zr * zr - zi * zi + data->c_r;
		zi = 2.0 * zr * zi + data->c_i;
		zr = tmp;
		i++;
	}
	return (i);
}
