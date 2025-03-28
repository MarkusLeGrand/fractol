/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:33:49 by lkantzer          #+#    #+#             */
/*   Updated: 2025/02/27 14:20:26 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("mlx_init failed");
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!data->win_ptr)
	{
		perror("mlx_new_window failed");
		return (1);
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img_ptr)
	{
		perror("mlx_new_image failed");
		return (1);
	}
	data->img_addr = mlx_get_data_addr(data->img_ptr,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_args(&data, argc, argv) != 0)
		return (1);
	if (init_mlx(&data) != 0)
		return (1);
	render(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
