#include "fractol.h"

int key_hook(int keycode, t_data *data)
{
    double move_factor;

    // Ajuster la vitesse de déplacement en fonction du niveau de zoom
    move_factor = 0.2 / data->zoom;

    if (keycode == 65307) // Touche ESC pour quitter
        exit(0);

    // Flèche gauche : déplace à gauche
    if (keycode == 65361)
        data->offset_x -= move_factor;

    // Flèche droite : déplace à droite
    if (keycode == 65363)
        data->offset_x += move_factor;

    // Flèche bas : déplace vers le bas
    if (keycode == 65364)
        data->offset_y += move_factor;

    // Flèche haut : déplace vers le haut
    if (keycode == 65362)
        data->offset_y -= move_factor;

    // Redessiner l'image après déplacement
    render(data);
    return (0);
}


/*
** Gestion de la molette pour zoomer et dézoomer "tout droit"
*/
int mouse_hook(int button, int x, int y, t_data *data)
{
    double zoom_factor = 1.1;

    (void)x; // Ignorer x et y car le zoom est "tout droit"
    (void)y;

    // Zoom in (molette haut)
    if (button == 4)
        data->zoom *= zoom_factor;

    // Zoom out (molette bas)
    else if (button == 5)
        data->zoom /= zoom_factor;

    // Redessiner l'image après le zoom
    render(data);
    return (0);
}

/*
** Fermer la fenêtre en cliquant sur la croix
*/
int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return (0);
}
