/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:05 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:29:06 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t e)
{
	size_t	t;
	void	*ptr;

	t = n * e;
	ptr = malloc(t);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, t);
	}
	return (ptr);
}
