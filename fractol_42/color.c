/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:00:00 by yourname          #+#    #+#             */
/*   Updated: 2025/02/16 17:19:09 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int	get_color_polynomial(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration >= max_iter)
		return (0x000000);
	t = (double)iteration / (double)max_iter;
	r = (int)(9.0 * (1.0 - t) * t * t * t * 255.0);
	g = (int)(15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0);
	b = (int)(8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0);
	return ((r << 16) | (g << 8) | b);
}

static int	get_color_psychedelic(t_data *data, int iteration)
{
	double	t;
	int		r;
	int		g;
	int		b;
	double	freq;

	if (iteration >= data->max_iter)
		return (0x000000);
	freq = 20.0;
	t = (freq * ((double)iteration / (double)data->max_iter))
		+ (data->hue_offset * 2.0 * M_PI);
	r = (int)(((sin(t) + 1.0) * 0.5) * 255.0);
	g = (int)(((sin(t + 2.0944) + 1.0) * 0.5) * 255.0);
	b = (int)(((sin(t + 4.1888) + 1.0) * 0.5) * 255.0);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(t_data *data, int iteration, double zr, double zi)
{
	(void)zr;
	(void)zi;
	if (iteration >= data->max_iter)
		return (0x000000);
	if (data->color_mode == 0)
		return ((get_color_polynomial(iteration, data->max_iter)));
	else if (data->color_mode == 1)
		return ((get_color_psychedelic(data, iteration)));
	return ((get_color_polynomial(iteration, data->max_iter)));
}
