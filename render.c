#include "fractol.h"

void render(t_data *data)
{
    int x, y;
    double re_min, re_max, im_min, im_max;
    double re, im;

    // Limites du plan complexe en fonction du zoom et du déplacement
    re_min = data->offset_x - (4.0 / data->zoom) / 2.0;
    re_max = data->offset_x + (4.0 / data->zoom) / 2.0;
    im_min = data->offset_y - (4.0 / data->zoom) / 2.0;
    im_max = data->offset_y + (4.0 / data->zoom) / 2.0;

    // Augmenter la précision en fonction du zoom
    data->max_iter = 50 + (int)(10 * log2(data->zoom));

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // Conversion pixel -> coordonnées complexes
            re = re_min + x * (re_max - re_min) / WIDTH;
            im = im_min + y * (im_max - im_min) / HEIGHT;

            // Calcul de la fractale
            if (data->fractal_type == 0)
                my_mlx_pixel_put(data, x, y, get_color(mandelbrot(re, im, data), data->max_iter));
            else if (data->fractal_type == 1)
                my_mlx_pixel_put(data, x, y, get_color(julia(re, im, data), data->max_iter));
            x++;
        }
        y++;
    }

    // Afficher l'image
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
