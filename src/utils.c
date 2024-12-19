/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:20:27 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/19 14:35:52 by camarcos         ###   ########.fr       */
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

// static void	sign_spaces(const char **str, int *sign)
// {
// 	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
// 		(*str)++;
// 	if (**str == '-' || **str == '+')
// 	{
// 		if (**str == '-')
// 			*sign = -1;
// 		(*str)++;
// 	}
// }

// static double	convert_to_double(const char *str, int sign)
// {
// 	double	result = 0.0;
// 	double	factor = 1.0;

// 	while (ft_isdigit(*str))
// 		result = result * 10.0 + (*str++ - '0');
// 	if (*str == '.')
// 	{
// 		str++;
// 		while (ft_isdigit(*str))
// 		{
// 			result = result * 10.0 + (*str - '0');
// 			factor *= 10.0;
// 			str++;
// 		}
// 	}
// 	return (sign * result / factor);
// }

// double	ft_atodbl(const char *str)
// {
// 	int		sign;

// 	sign = 1;
// 	if (!is_valid_number(str))
// 	{
// 		ft_putendl_fd("Error: no es un número válido.", 1);
// 		exit(1);
// 	}
// 	handle_sign_and_spaces(&str, &sign);
// 	return (convert_to_double(str, sign));
// }

int	handle_spaces_and_sign(const char **str)
{
	int	sign;

	sign = 1;
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

int	is_valid_number(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str) || (!ft_isdigit(*str) && *str != '.'))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
			str++;
	}
	return (*str == '\0');
}

double	convert_to_double(const char **str, int sign)
{
	double	result;
	double	factor;

	result = 0.0;
	factor = 1.0;
	while (ft_isdigit(**str))
		result = result * 10.0 + (**str++ - '0');
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(*str))
		{
			result = result * 10.0 + (*str - '0');
			factor *= 10.0;
			(*str)++;
		}
	}
	return (sign * result / factor);
}

double	ft_atodbl(const char *str)
{
	int	sign;

	if (!is_valid_number(str))
	{
		ft_putendl_fd("Error: no es un número válido.", 1);
		exit(1);
	}
	sign = handle_spaces_and_sign(&str);
	return (convert_to_double(&str, sign));
}
