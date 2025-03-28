/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:33:55 by lkantzer          #+#    #+#             */
/*   Updated: 2025/03/20 12:26:24 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <Real_part> <Imag_part>\n");
}

static void	init_mandelbrot(t_data *data)
{
	data->fractal_type = 0;
	data->zoom = 1.0;
	data->offset_x = -0.5;
	data->offset_y = 0.0;
	data->max_iter = 50;
	data->c_r = 0.0;
	data->c_i = 0.0;
	data->color_mode = 0;
	data->hue_offset = 0.0;
}

static int	init_julia(t_data *data, int argc, char **argv)
{
	if (argc < 4)
	{
		print_usage();
		return (1);
	}
	data->fractal_type = 1;
	data->c_r = atof(argv[2]);
	data->c_i = atof(argv[3]);
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->max_iter = 50;
	data->color_mode = 0;
	data->hue_offset = 0.0;
	return (0);
}

int	parse_args(t_data *data, int argc, char **argv)
{
	if (argc < 2)
	{
		print_usage();
		return (1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		init_mandelbrot(data);
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (init_julia(data, argc, argv) != 0)
			return (1);
	}
	else
	{
		print_usage();
		return (1);
	}
	return (0);
}
