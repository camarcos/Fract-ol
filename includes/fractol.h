/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:29:45 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/17 12:28:37 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

// Tamaño de la ventana
# define SIZE 800

// Teclas y eventos
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define R 15
# define C 8
# define J 38
# define M 46
# define P 35
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// Estructura principal
typedef struct s_fractal
{
    void    *mlx;
    void    *window;
    void    *image;
    char    *pointer_to_image;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
    int     x;
    int     y;
    double  zoom;
    double  offset_x;
    double  offset_y;
    double  zx;
    double  zy;
    double  cx;
    double  cy;
    int     color;
    int     max_iterations;
    char    *name;
}               t_fractal;

// Funciones principales
void    calculate_burning_ship(t_fractal *fractal);
void    calculate_mandelbrot(t_fractal *fractal);
void    calculate_julia(t_fractal *fractal);

void    draw_burning_ship(t_fractal *fractal);
void    *mandelbrot(void *fractal_void);
void    julia(t_fractal *fractal);

int     draw_fractal(t_fractal *fractal, char *query);

void    init_fractal(t_fractal *fractal);
void    init_mlx(t_fractal *fractal);

void    put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
void    set_random_julia(double *cx, double *cy);

void    zoom(t_fractal *fractal, int x, int y, int zoom);
void    change_iterations(t_fractal *fractal, int key_code);

int     key_hook(int key_code, t_fractal *fractal);
int     mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
int     exit_fractal(t_fractal *fractal);

double  generate_random_c(void);

#endif
