/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:56:32 by yourname          #+#    #+#             */
/*   Updated: 2025/03/28 13:58:11 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractal_type;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	c_r;
	double	c_i;
	int		max_iter;
	int		color_mode;
	double	hue_offset;
}	t_data;

typedef struct s_range
{
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
}	t_range;

int		parse_args(t_data *data, int argc, char **argv);
void	render(t_data *data);
int		mandelbrot(double cr, double ci, t_data *data);
int		julia(double zr, double zi, t_data *data);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		close_window(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(t_data *data, int iteration, double zr, double zi);

#endif
