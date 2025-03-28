/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:33:58 by yourname          #+#    #+#             */
/*   Updated: 2025/02/16 16:44:57 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_fractal_row(t_data *data, int y, t_range range)
{
	int		x;
	double	re;
	double	im;
	int		iter;
	int		color;

	x = 0;
	while (x < WIDTH)
	{
		re = range.re_min + (double)x * (range.re_max - range.re_min)
			/ (double)WIDTH;
		im = range.im_min + (double)y * (range.im_max - range.im_min)
			/ (double)HEIGHT;
		if (data->fractal_type == 0)
			iter = mandelbrot(re, im, data);
		else
			iter = julia(re, im, data);
		color = get_color(data, iter, re, im);
		my_mlx_pixel_put(data, x, y, color);
		x++;
	}
}

static void	draw_fractal(t_data *data, t_range range)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		draw_fractal_row(data, y, range);
		y++;
	}
}

void	render(t_data *data)
{
	t_range	range;

	range.re_min = data->offset_x - (4.0 / data->zoom) / 2.0;
	range.re_max = data->offset_x + (4.0 / data->zoom) / 2.0;
	range.im_min = data->offset_y - (4.0 / data->zoom) / 2.0;
	range.im_max = data->offset_y + (4.0 / data->zoom) / 2.0;
	data->max_iter = 50 + (int)(10.0 * log2(data->zoom));
	if (data->max_iter < 50)
		data->max_iter = 50;
	draw_fractal(data, range);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_ptr, 0, 0);
}
