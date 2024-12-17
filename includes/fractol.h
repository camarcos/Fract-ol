/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:29:45 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/17 10:40:01 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//# include "libft/libft.h"
//# include "minilibx/mlx.h"
# include <math.h>
# include <pthread.h>

# define SIZE 700
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

//utils
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int			exit_fractal(t_fractal *fractal);
double		generate_random_c(void);
void		change_iterations(t_fractal *fractal, int key_code);

//init
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

//mandel_julia
void		calculate_mandelbrot(t_fractal *fractal);
void		calculate_julia(t_fractal *fractal);

//calculate
void		calculate_burning_ship(t_fractal *fractal);

//fractol
int			draw_fractal(t_fractal *fractal, char *query);
int			main(int argc, char **argv);

//mouse_keys
void		zoom(t_fractal *fractal, int x, int y, int zoom);
void		set_random_julia(double *cx, double *cy);
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

//draw
void		*mandelbrot(void *fractal_void);
void		julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

#endif