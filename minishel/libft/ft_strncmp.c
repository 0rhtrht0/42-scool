/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:32:14 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:15 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	diff(char s1, char s2)
{
	int	i;
	int	j;
	int	k;

	i = (unsigned char)(s1);
	j = (unsigned char)(s2);
	k = i - j;
	return (k);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (diff(s1[i], s2[i]) == 0)
		{
			i++;
			k = 0;
		}
		else
			return (diff(s1[i], s2[i]));
	}
	return (k);
}
