/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:31:38 by horandri          #+#    #+#             */
/*   Updated: 2024/12/20 12:41:28 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free (s1);
	return (p);
}

char	*ft_strjoin2(char *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '/')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '/';
	i++;
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	// free (s1);
	return (p);
}

char	*ft_strjoin_char(char *s1)
{
	char	*p;
	int		i;

	p = malloc((ft_strlen(s1) +  2) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i++] = '/';
	p[i] = '\0';
	free (s1);
	return (p);
}
