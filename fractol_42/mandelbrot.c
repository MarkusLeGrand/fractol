/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:56:20 by lkantzer          #+#    #+#             */
/*   Updated: 2025/02/16 16:33:53 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci, t_data *data)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while ((zr * zr + zi * zi) <= 4.0 && i < data->max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}
