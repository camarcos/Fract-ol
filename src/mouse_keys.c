/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:49 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/18 13:22:39 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void zoom(t_fractal *fractal, int zoom)
{
	double zoom_level;
	double center_x;
	double center_y;

	zoom_level = 1.42;
	center_x = 800 / 2.0;
	center_y = 800 / 2.0;

	if (zoom == 1)
	{
		fractal->offset_x = (center_x / fractal->zoom + fractal->offset_x) 
							- (center_x / (fractal->zoom * zoom_level));
		fractal->offset_y = (center_y / fractal->zoom + fractal->offset_y) 
							- (center_y / (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (center_x / fractal->zoom + fractal->offset_x) 
							- (center_x / (fractal->zoom / zoom_level));
		fractal->offset_y = (center_y / fractal->zoom + fractal->offset_y) 
							- (center_y / (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
}

void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
