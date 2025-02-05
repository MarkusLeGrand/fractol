#include "fractol.h"

void render(t_data *data)
{
    int x, y;
    double re, im;
    double re_min, re_max, im_min, im_max;
    int iteration;
    int color;

    // Limites en fonction du zoom et offsets
    re_min = data->offset_x - (4.0 / data->zoom) / 2.0;
    re_max = data->offset_x + (4.0 / data->zoom) / 2.0;
    im_min = data->offset_y - (4.0 / data->zoom) / 2.0;
    im_max = data->offset_y + (4.0 / data->zoom) / 2.0;

    // Ajustement dynamique du max_iter en fonction du zoom
    // Evitez de dépasser 500-1000 si vous craignez les perfs
    data->max_iter = 50 + (int)(10.0 * log2(data->zoom));
    if (data->max_iter < 50)
        data->max_iter = 50;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // Conversion pixel -> coordonnées complexes
            re = re_min + x * (re_max - re_min) / WIDTH;
            im = im_min + y * (im_max - im_min) / HEIGHT;

            // Calcul du nombre d'itérations (divergence)
            if (data->fractal_type == 0)
                iteration = mandelbrot(re, im, data);
            else
                iteration = julia(re, im, data);

            // Couleur => on passe re, im comme "zr, zi"
            // Si on veut vraiment smooth coloring parfait, on devrait
            // récupérer le zr, zi final dans la fonction fractale.
            color = get_color(iteration, data->max_iter,
                              data->color_mode, re, im,
                              data->hue_offset);

            my_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
    }
    // On affiche l'image dans la fenêtre
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
