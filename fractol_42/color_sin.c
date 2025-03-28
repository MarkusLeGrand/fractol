/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:55:54 by lkantzer          #+#    #+#             */
/*   Updated: 2025/02/16 16:56:50 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	sin_color(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration >= max_iter)
		return (0x000000);
	t = (double)iteration / (double)max_iter;
	r = (int)(((sin(5.0 * t + 0.0) * 0.5) + 0.5) * 255);
	g = (int)(((sin(5.0 * t + 2.0) * 0.5) + 0.5) * 255);
	b = (int)(((sin(5.0 * t + 4.0) * 0.5) + 0.5) * 255);
	return ((r << 16) | (g << 8) | b);
}
