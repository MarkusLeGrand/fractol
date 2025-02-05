#include "fractol.h"

/*
** key_hook :
**  - Gérer déplacement, changement de palette, offset de couleur, etc.
*/
int key_hook(int keycode, t_data *data)
{
    double move_factor;

    // Ajuster la vitesse de déplacement en fonction du zoom
    move_factor = 0.2 / data->zoom;

    if (keycode == 65307) // ESC
        exit(0);

    // Flèches directionnelles
    if (keycode == 65361) // gauche
        data->offset_x -= move_factor;
    if (keycode == 65363) // droite
        data->offset_x += move_factor;
    if (keycode == 65362) // haut
        data->offset_y -= move_factor;
    if (keycode == 65364) // bas
        data->offset_y += move_factor;

    // Changement de palette
    if (keycode == '1') // ascii code 49 => touche '1'
        data->color_mode = 0; // polynomial
    if (keycode == '2')
        data->color_mode = 1; // hsv simple
    if (keycode == '3')
        data->color_mode = 2; // hsv cycles
    if (keycode == '4')
        data->color_mode = 3; // smooth

    // Décalage de la teinte (offset) avec la touche 'c' (ascii 99)
    if (keycode == 'c' || keycode == 'C')
    {
        data->hue_offset += 0.05; // Incrémente l’offset de hue
        if (data->hue_offset > 1.0)
            data->hue_offset -= 1.0;
    }

    render(data);
    return (0);
}

/*
** mouse_hook :
**  - Zoom "tout droit" (molette 4=zoom in, 5=zoom out).
*/
int mouse_hook(int button, int x, int y, t_data *data)
{
    double zoom_factor = 1.1;

    (void)x;
    (void)y;
    if (button == 4)
        data->zoom *= zoom_factor;
    else if (button == 5)
        data->zoom /= zoom_factor;

    render(data);
    return (0);
}

/*
** Fermer la fenêtre avec la croix
*/
int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return (0);
}
