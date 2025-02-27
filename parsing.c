/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by yourname          #+#    #+#             */
/*   Updated: 2025/02/12 17:28:36 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Affiche l'usage possible
*/
static void	print_usage(void)
{
	printf("Usage:\n");
	printf("  ./fractol mandelbrot\n");
	printf("  ./fractol julia <Real_part> <Imag_part>\n");
}

int	parse_args(t_data *data, int argc, char **argv)
{
	if (argc < 2)
	{
		print_usage();
		return (1);
	}
	if (strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractal_type = 0;
		data->zoom = 1.0;
		data->offset_x = -0.5; // Valeur courante pour mandelbrot
		data->offset_y = 0.0;
		data->max_iter = 50;
	}
	else if (strcmp(argv[1], "julia") == 0)
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
	}
	else
	{
		print_usage();
		return (1);
	}
	return (0);
}
