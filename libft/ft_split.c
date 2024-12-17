/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:34:25 by camarcos          #+#    #+#             */
/*   Updated: 2024/04/18 13:59:58 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	const char	*reco;
	size_t		count;

	reco = s;
	count = 0;
	while (*reco)
	{
		while (*reco == c && *reco != '\0')
			reco++;
		if (*reco != '\0')
		{
			count++;
			while (*reco && (*reco != c))
				reco++;
		}
	}
	return (count);
}

static char	**free_memarr(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

static char	*allocate_memword(char const *start, size_t len)
{
	char	*word;

	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	const char	*start;
	size_t		numwords;
	size_t		i;

	if (!s)
		return (NULL);
	numwords = count_words(s, c);
	arr = (char **)ft_calloc(numwords + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < numwords)
	{
		while (*s == c && *s)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		arr[i] = allocate_memword(start, s - start);
		if (!arr[i])
			return (free_memarr(arr, i));
	}
	arr[i] = NULL;
	return (arr);
}
