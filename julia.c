#include "fractol.h"

int	julia(double zr, double zi, t_data *data)
{
	double tmp;
	int i;

	i = 0;
	while ((zr * zr + zi * zi) <= 4.0 && i < data->max_iter)
	{
		tmp = zr * zr - zi * zi + data->c_r;
		zi = 2.0 * zr * zi + data->c_i;
		zr = tmp;
		i++;
	}
	return (i);
}