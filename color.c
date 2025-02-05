#include "fractol.h"
#include <math.h>

/*
** ====================== hsv_to_rgb ======================
** Convertit des valeurs HSV (chacune entre 0.0 et 1.0)
** en couleur RGB (0xRRGGBB).
*/
static int	hsv_to_rgb(double h, double s, double v)
{
	double	r;
	double	g;
	double	b;
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	if (s == 0.0)
	{
		r = v;
		g = v;
		b = v;
		return ((int)(r * 255) << 16)
			| ((int)(g * 255) << 8)
			| (int)(b * 255);
	}
	h = fmod(h, 1.0) * 6.0;
	i = (int)h;
	f = h - i;
	p = v * (1.0 - s);
	q = v * (1.0 - s * f);
	t = v * (1.0 - s * (1.0 - f));
	if (i == 0)
	{
		r = v;
		g = t;
		b = p;
	}
	else if (i == 1)
	{
		r = q;
		g = v;
		b = p;
	}
	else if (i == 2)
	{
		r = p;
		g = v;
		b = t;
	}
	else if (i == 3)
	{
		r = p;
		g = q;
		b = v;
	}
	else if (i == 4)
	{
		r = t;
		g = p;
		b = v;
	}
	else
	{
		r = v;
		g = p;
		b = q;
	}
	return ((int)(r * 255) << 16)
		| ((int)(g * 255) << 8)
		| (int)(b * 255);
}

/*
** ====================== get_color_polynomial ======================
** Palette polynomiale "classique" (exemple).
*/
static int	get_color_polynomial(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration >= max_iter)
		return (0x000000); // noir si stable
	t = (double)iteration / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

/*
** ====================== get_color_hsv_simple ======================
** Couleur HSV simple : une seule "rotation" de hue [0..1].
*/
static int	get_color_hsv_simple(int iteration, int max_iter)
{
	double	h;

	if (iteration >= max_iter)
		return (0x000000);
	h = (double)iteration / (double)max_iter; // [0..1]
	return (hsv_to_rgb(h, 1.0, 1.0));
}

/*
** ====================== get_color_hsv_cycles ======================
** Couleur HSV avec plusieurs "cycles" d'arc-en-ciel,
** et un offset de teinte (hue_offset) pour décaler la palette.
*/
static int	get_color_hsv_cycles(int iteration,
								 int max_iter,
								 double hue_offset)
{
	double	cycles;
	double	h;

	if (iteration >= max_iter)
		return (0x000000);

	cycles = 5.0; // 5 tours d'arc-en-ciel
	h = ((double)iteration / (double)max_iter) * cycles;
	h = fmod(h + hue_offset, 1.0);
	return (hsv_to_rgb(h, 1.0, 1.0));
}

/*
** ====================== get_color_smooth ======================
** Continuous coloring / smooth shading.
** iteration + 1 - log(log(|z|)) / log(2)
** => On obtient un "index" flottant pour adoucir les bandes.
*/
static int	get_color_smooth(int iteration,
							 int max_iter,
							 double zr,
							 double zi,
							 double hue_offset)
{
	double	mag;
	double	nu;
	double	index;
	double	h;
	double	cycles;

	if (iteration >= max_iter)
		return (0x000000);

	// Calcul de la magnitude finale
	mag = sqrt(zr * zr + zi * zi);
	if (mag < 1e-9)
		mag = 1e-9;

	// Continuous index
	nu = log(log(mag) / log(2)) / log(2);
	index = iteration + 1.0 - nu;

	// Nombre de tours de hue
	cycles = 3.0;
	h = fmod((index / max_iter) * cycles + hue_offset, 1.0);

	return (hsv_to_rgb(h, 1.0, 1.0));
}

/*
** ====================== get_color ======================
** Switch sur le color_mode :
**   0 = polynomial,
**   1 = HSV simple,
**   2 = HSV cycles,
**   3 = smooth coloring.
** On passe zr, zi, hue_offset pour le mode 3 (smooth) ou mode 2 (offset).
*/
int	get_color(int iteration,
			  int max_iter,
			  int color_mode,
			  double zr,
			  double zi,
			  double hue_offset)
{
	if (color_mode == 0)
		return (get_color_polynomial(iteration, max_iter));
	else if (color_mode == 1)
		return (get_color_hsv_simple(iteration, max_iter));
	else if (color_mode == 2)
		return (get_color_hsv_cycles(iteration, max_iter, hue_offset));
	else if (color_mode == 3)
		return (get_color_smooth(iteration, max_iter, zr, zi, hue_offset));
	// Par défaut, renvoyer polynomial
	return (get_color_polynomial(iteration, max_iter));
}
