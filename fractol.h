#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>  // Inclut mlx.h depuis minilibx-linux
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

/*
** Dimensions de la fenêtre
*/
# define WIDTH 800
# define HEIGHT 600

/*
** Structure principale
*/
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		fractal_type; // 0 = Mandelbrot, 1 = Julia
	double	zoom;
	double	offset_x;
	double	offset_y;

	double	c_r; // Paramètres pour Julia
	double	c_i;
	int		max_iter;

	/* -------- Ajouts pour la couleur -------- */
	int		color_mode;   // Choix de la palette (0,1,2,3,...)
	double	hue_offset;   // Offset pour faire tourner la palette
}	t_data;

/*
** Prototypes des fonctions
*/

/* parse_args.c */
int		parse_args(t_data *data, int argc, char **argv);

/* render.c */
void	render(t_data *data);

/* mandelbrot.c */
int		mandelbrot(double cr, double ci, t_data *data);

/* julia.c */
int		julia(double zr, double zi, t_data *data);

/* events.c */
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		close_window(t_data *data);

/* utils.c */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* color.c */
int		get_color(int iteration, int max_iter, int color_mode,
				double zr, double zi, double hue_offset);

#endif
