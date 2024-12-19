/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:21:37 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/19 14:18:06 by camarcos         ###   ########.fr       */
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
	else
	{
		ft_putendl_fd("Available fractals: mandel, julia", 1);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

t_fractal	*initialize_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	if (!(fractal = malloc(sizeof(t_fractal))))
		return (ft_putendl_fd("Error: Memory allocation failed.", 2), NULL);
	*fractal = (t_fractal){.cx = 0.0, .cy = 0.0, .zoom = 1.0, 
		.offset_x = 0.0, .offset_y = 0.0, .name = argv[1]};
	if (!ft_strncmp(argv[1], "mandel", 10) && (argc == 2 || argc > 2))
		return (fractal); 
	if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
	{
		fractal->cx = ft_atodbl(argv[2]);
		fractal->cy = ft_atodbl(argv[3]);
		return (fractal);
	}
	free(fractal);
	return (ft_putendl_fd("Error: Invalid arguments.", 2), NULL);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = initialize_fractal(argc, argv);
	if (!fractal)
		return (1);
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);

	free(fractal);
	return (0);
}
