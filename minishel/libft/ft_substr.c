 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:32:44 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:45 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	y;
	size_t	n;

	y = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n)
		return (ft_strdup(""));
	if ((start + len) > n)
		len = n - start;
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	s += start;
	while (y < len)
	{
		p[y] = *s;
		s++;
		y++;
	}
	p[y] = '\0';
	return (p);
}
