/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:29:45 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/21 19:06:00 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// Tamaño de la ventana
# define SIZE 800

# define THREAD_WIDTH 7
# define THREAD_NUMBER 100

// Keycodes
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define R 114
# define C 99
# define J 106
# define M 109
# define P 112

// Mousecodes
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// Estructura principal
typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		window_width;
	int		window_height;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	int		max_iterations;
	char	*name;
}			t_fractal;

// utils
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
int			exit_fractal(t_fractal *fractal);
int			sign_whitespace(const char **str);
void		validate_number_format(const char *str);
double		ft_atodbl(const char *str);

// fractol
int			draw_fractal(t_fractal *fractal, char *query);
t_fractal	*initialize_fractal(int argc, char **argv);
void		change_iterations(t_fractal *fractal, int key_code);
int			main(int argc, char **argv);

// init
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandel_julia
void		calculate_mandelbrot(t_fractal *fractal);
void		*mandelbrot(void *fractal_void);
void		calculate_julia(t_fractal *fractal);
void		julia(t_fractal *fractal);

// mouse_keys
void		zoom(t_fractal *fractal, int zoom, int x, int y);
double		generate_random_c(void);
void		set_random_julia(double *cx, double *cy);
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

#endif
