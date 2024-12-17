/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:21:37 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/17 17:59:38 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandel", 7) == 0)
		mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.745429;
			fractal->cy = 0.05;
		}
		julia(fractal);
	}
	else if (ft_strncmp(query, "ship", 5) == 0)
		draw_burning_ship(fractal);
	else
	{
		ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
