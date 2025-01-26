#include "fractol.h"

/*
** Placer un pixel sur l'image
*/
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = data->img_addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

/*
** Générer une couleur en fonction des itérations
*/
int get_color(int iteration, int max_iter)
{
    double t;
    int r, g, b;

    if (iteration == max_iter)
        return (0x000000); // Noir pour les points dans l'ensemble
    t = (double)iteration / (double)max_iter;
    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return ((r << 16) | (g << 8) | b);
}
