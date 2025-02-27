#include "fractol.h"

int	mandelbrot(double cr, double ci, t_data *data)
{
	double zr;
	double zi;
	double tmp;
	int i;

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