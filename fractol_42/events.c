/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:53:32 by lkantzer          #+#    #+#             */
/*   Updated: 2025/02/16 17:20:50 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *data)
{
	double	move_factor;

	move_factor = 0.2 / data->zoom;
	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		data->offset_x -= move_factor;
	if (keycode == 65363)
		data->offset_x += move_factor;
	if (keycode == 65362)
		data->offset_y -= move_factor;
	if (keycode == 65364)
		data->offset_y += move_factor;
	if (keycode == '1')
		data->color_mode = 0;
	if (keycode == '2')
		data->color_mode = 1;
	if (keycode == 'c' || keycode == 'C')
	{
		data->hue_offset += 0.05;
		if (data->hue_offset > 1.0)
			data->hue_offset -= 1.0;
	}
	render(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= zoom_factor;
	else if (button == 5)
		data->zoom /= zoom_factor;
	render(data);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}
