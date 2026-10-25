# fract-ol

> Un explorateur de fractales en C avec la MiniLibX : les ensembles de Mandelbrot et de Julia, calculés pixel par pixel, avec zoom, déplacement et palettes de couleurs.

## À propos

`fract-ol` est un projet graphique du cursus de l'école 42. Le programme ouvre une fenêtre de 800×600 pixels et y dessine une fractale. Chaque pixel correspond à un nombre complexe, et sa couleur dépend du nombre d'itérations nécessaires pour que la suite `z(n+1) = z(n)² + c` diverge.

Le projet sert à découvrir la programmation graphique bas niveau (images en mémoire, gestion des événements clavier et souris) et la manipulation des nombres complexes.

## Fonctionnalités

- **Ensemble de Mandelbrot** : `z0 = 0` et `c` = le point du pixel.
- **Ensemble de Julia** : `z0` = le point du pixel et `c` fixé par l'utilisateur en ligne de commande, ce qui permet d'explorer une infinité de formes.
- **Zoom** à la molette, sans limite fixe.
- **Nombre d'itérations adaptatif** : `max_iter = 50 + 10 × log2(zoom)`, pour garder des détails nets en zoomant.
- **Déplacement** avec les flèches. Le pas s'adapte au niveau de zoom.
- **Deux palettes de couleurs** :
  - polynomiale (dégradé lisse) ;
  - « psychédélique », basée sur trois sinusoïdes déphasées, avec rotation de teinte.
- Rendu dans une image hors écran (`mlx_new_image`), puis affichage en une seule fois pour éviter le scintillement.
- Fermeture propre avec `Échap` ou la croix de la fenêtre.

## Compilation & utilisation

Prérequis (Linux) : `cc`, `make`, X11 et la [MiniLibX](https://github.com/42Paris/minilibx-linux) (bibliothèque graphique de 42).

La version finale du projet se trouve dans le dossier `fractol_42/`. La MiniLibX n'est pas incluse dans le dépôt. Il faut la placer dans `fractol_42/minilibx-linux/` et la compiler avant de compiler le projet :

```bash
sudo apt install xorg libxext-dev libbsd-dev   # dépendances X11 de la MiniLibX
cd fractol_42
git clone https://github.com/42Paris/minilibx-linux.git
make -C minilibx-linux
make            # compile la libft (libftV2/) puis le binaire ./fractol
```

Règles disponibles : `make`, `make clean`, `make fclean`, `make re`.

Utilisation :

```bash
./fractol mandelbrot
./fractol julia <partie_reelle> <partie_imaginaire>
```

Exemples :

```bash
./fractol mandelbrot
./fractol julia -0.8 0.156
./fractol julia 0.285 0.01
./fractol julia -0.4 0.6
```

Si la fractale demandée est inconnue, ou si les paramètres de Julia manquent, le programme affiche son usage et s'arrête.

### Lancer sous WSL

Sous WSL, il faut un serveur X sur Windows (par exemple VcXsrv) et configurer l'affichage avant de lancer le programme :

```bash
export DISPLAY=$(ip route show default | awk '/default/ {print $3}'):0
export LIBGL_ALWAYS_INDIRECT=1
```

## Contrôles

| Entrée                | Action                                                   |
|-----------------------|----------------------------------------------------------|
| Molette vers le haut  | Zoom avant (×1.1)                                        |
| Molette vers le bas   | Zoom arrière (÷1.1)                                      |
| Flèches ← → ↑ ↓       | Déplacer la vue                                          |
| `1`                   | Palette polynomiale                                      |
| `2`                   | Palette psychédélique (sinusoïdale)                      |
| `C`                   | Faire tourner la teinte (visible avec la palette `2`)    |
| `Échap` / croix       | Quitter                                                  |

## Approche technique

- **Du pixel au complexe.** La vue est définie par un centre (`offset_x`, `offset_y`) et un facteur `zoom`. La fenêtre couvre une largeur de `4 / zoom` dans le plan complexe. `render()` calcule les bornes `re_min / re_max / im_min / im_max` (structure `t_range`), puis convertit chaque pixel `(x, y)` en `(re, im)` par interpolation linéaire.
- **Itération.** Mandelbrot et Julia utilisent la même boucle d'échappement : on itère `z = z² + c` tant que `|z|² ≤ 4` et que `i < max_iter`. Seuls le point de départ et la valeur de `c` changent entre les deux fractales.
- **Couleurs.**
  - Les points qui ne divergent pas sont noirs.
  - Pour les autres, on calcule `t = iter / max_iter`.
  - La palette polynomiale applique `r = 9(1−t)t³`, `g = 15(1−t)²t²`, `b = 8.5(1−t)³t`.
  - La palette psychédélique applique trois `sin` déphasés de 2π/3, avec un décalage `hue_offset` modifié par la touche `C`.
- **Écriture directe dans l'image.** `my_mlx_pixel_put` écrit la couleur directement à l'adresse renvoyée par `mlx_get_data_addr`, ce qui est bien plus rapide que `mlx_pixel_put`. L'image est ensuite affichée en une seule fois avec `mlx_put_image_to_window`.
- **Événements.** Les fonctions `mlx_key_hook`, `mlx_mouse_hook` et `mlx_hook` (événement 17, fermeture de la fenêtre) mettent à jour l'état dans `t_data`, puis relancent un rendu complet.
- **Libft maison.** Le projet utilise ma `libft` (avec `ft_printf`), compilée automatiquement par le `Makefile`.

## Structure du projet

```
fractol/
├── fractol_42/          # version finale du projet
│   ├── Makefile
│   ├── fractol.h        # structures t_data / t_range, prototypes
│   ├── main.c           # initialisation MiniLibX, hooks, boucle
│   ├── parsing.c        # lecture des arguments, valeurs initiales
│   ├── render.c         # conversion pixel -> complexe, dessin de l'image
│   ├── mandelbrot.c     # itération de Mandelbrot
│   ├── julia.c          # itération de Julia
│   ├── color.c          # palettes de couleurs
│   ├── color_sin.c      # palette sinusoïdale alternative (non branchée)
│   ├── events.c         # clavier, souris, fermeture
│   ├── utils.c          # écriture d'un pixel dans l'image
│   └── libftV2/         # ma libft + ft_printf
└── *.c, fractol.h, Makefile   # premier prototype (sans libft), conservé à la racine
```

## Ce que j'ai appris

- Utiliser une bibliothèque graphique minimaliste : fenêtre, image hors écran, accès direct au buffer de pixels (`bits_per_pixel`, `line_length`).
- Programmer de façon événementielle avec des hooks clavier et souris et une boucle principale (`mlx_loop`).
- Faire passer des coordonnées de l'écran au plan complexe, puis gérer le zoom et le déplacement.
- Comprendre les fractales d'échappement et le compromis entre précision (nombre d'itérations) et performance.
- Générer des couleurs de façon procédurale à partir d'un simple compteur d'itérations.
- Organiser un projet C avec une bibliothèque personnelle compilée par un `Makefile` dédié.
