/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:26:04 by camarcos          #+#    #+#             */
/*   Updated: 2024/04/18 13:59:41 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *org, size_t len)
{
	void	*dinicio;

	if (!dst && !org)
		return (0);
	dinicio = dst;
	if (org < dst)
	{
		org += len;
		dst += len;
		while (len--)
			*(char *)--dst = *(char *)--org;
	}
	else
		while (len--)
			*(char *)dst++ = *(char *)org++;
	return (dinicio);
}
