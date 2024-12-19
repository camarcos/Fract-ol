/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:20:27 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/18 18:33:36 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = (int *)fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

int	is_valid_number(const char *str)
{
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    if (*str == '-' || *str == '+')
        str++;
    if (!(*str) || (!isdigit(*str) && *str != '.'))
        return (0);
    while (isdigit(*str))
        str++;
    if (*str == '.')
    {
        str++;
        while (isdigit(*str))
            str++;
    }
    return (*str == '\0');
}

double	ft_atodbl(const char *str)
{
    double	result = 0.0;
    double	factor = 1.0;
    int		sign = 1;

    if (!is_valid_number(str))
    {
		ft_putendl_fd("Error: no es un número válido.", 1);
        return (0.0);
    }
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (isdigit(*str))
        result = result * 10.0 + (*str++ - '0');
    if (*str == '.')
        while (isdigit(*++str))
        {
            result = result * 10.0 + (*str - '0');
            factor *= 10.0;
        }
    return (sign * result / factor);
}
