/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:30:29 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:30:30 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	if (pdst < psrc)
	{
		while (n-- > 0)
		{
			*pdst++ = *psrc++;
		}
	}
	else if (pdst > psrc)
	{
		pdst += n;
		psrc += n;
		while (n-- > 0)
		{
			*(--pdst) = *(--psrc);
		}
	}
	return (dest);
}
