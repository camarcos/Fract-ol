/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:26:56 by camarcos          #+#    #+#             */
/*   Updated: 2024/04/18 13:58:19 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *org, size_t sizedst)
{
	size_t	londst;
	size_t	lonorg;
	size_t	cont;

	londst = ft_strlen(dst);
	lonorg = ft_strlen(org);
	if (sizedst <= londst)
	{
		return (lonorg + sizedst);
	}
	cont = londst;
	while (*org != '\0' && cont < (sizedst - 1))
	{
		*(dst + cont++) = *org++;
	}
	*(dst + cont) = '\0';
	return (londst + lonorg);
}
