/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:30:07 by horandri          #+#    #+#             */
/*   Updated: 2024/12/13 13:26:44 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	p = str;
	uc = c;
	while (n-- != 0)
	{
		if (*p == uc)
			return ((void *) p);
		p++;
	}
	return (NULL);
}
