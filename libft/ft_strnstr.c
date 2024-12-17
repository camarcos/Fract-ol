/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:27:55 by camarcos          #+#    #+#             */
/*   Updated: 2024/04/18 13:58:36 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*haystack_mem;
	const char	*needle_mem;
	size_t		i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = len;
		haystack_mem = haystack;
		needle_mem = needle;
		while (i-- > 0 && *haystack_mem && *needle_mem
			&& *haystack_mem == *needle_mem)
		{
			haystack_mem++;
			needle_mem++;
		}
		if (*needle_mem == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
