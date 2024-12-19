/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:20:27 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/19 16:28:28 by carolinamc       ###   ########.fr       */
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

// int	is_valid_number(const char *str)
// {
// 	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 		str++;
// 	if (!(*str) || (!ft_isdigit(*str) && *str != '.'))
// 		return (0);
// 	while (ft_isdigit(*str))
// 		str++;
// 	if (*str == '.')
// 	{
// 		str++;
// 		while (ft_isdigit(*str))
// 			str++;
// 	}
// 	return (*str == '\0');
// }

// double	ft_atodbl(const char *str)
// {
// 	double	result;
// 	double	factor;
// 	int		sign;

// 	result = 0.0;
// 	factor = 1.0;
// 	sign = 1;
// 	if (!is_valid_number(str))
// 	{
// 		ft_putendl_fd("Error: no es un número válido.", 1);
// 		exit(1);
// 	}
// 	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
// 		str++;
// 	if (*str == '-' || *str == '+')
// 		sign = (*str++ == '-') ? -1 : 1;
// 	while (ft_isdigit(*str))
// 		result = result * 10.0 + (*str++ - '0');
// 	if (*str == '.')
// 		while (ft_isdigit(*++str))
// 		{
// 			result = result * 10.0 + (*str - '0');
// 			factor *= 10.0;
// 		}
// 	return (sign * result / factor);
// }

int	sign_whitespace(const char **str)
{
	int	sign;

	sing = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

void	validate_number_format(const char *str)
{
	const char	*start;

	start = str;
	if (!(*str) || (!ft_isdigit(*str) && *str != '.'))
	{
		ft_putendl_fd("Error: no es un número válido.", 1);
		exit(1);
	}
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
			str++;
	}
	if (*str != '\0')
	{
		ft_putendl_fd("Error: no es un número válido.", 1);
		exit(1);
	}
}

double	ft_atodbl(const char *str)
{
	double	result;
	double	factor;
	int		sign;

	result = 0.0;
	factor = 1.0;
	sign = parse_sign_and_whitespace(&str);
	validate_number_format(str);
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			result = result * 10.0 + (*str - '0');
			factor *= 10.0;
			str++;
		}
	}
	return (sign * result / factor);
}
