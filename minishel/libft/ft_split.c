/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:31:08 by horandri          #+#    #+#             */
/*   Updated: 2024/12/22 18:24:52 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

static int	ttab(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	strikt(char **p)
{
	int	i;

	i = 0;
	while (p[i] != NULL)
		free(p[i++]);
	free(p);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		wd;

	if (!s)
		return (NULL);
	wd = ttab(s, c);
	result = (char **)malloc((wd + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < wd)
	{
		while (*s && *s == c)
			s++;
		result[i] = ft_substr(s, 0, ft_strchr(s, c) - s);
		if (!result[i])
		{
			strikt(result);
			return (NULL);
		}
		s += ft_strlen(result[i++]);
	}
	result[i] = NULL;
	return (result);
}
