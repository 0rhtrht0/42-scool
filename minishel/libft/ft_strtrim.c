/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:32:37 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:38 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	i = ft_strlen(s1);
	end = i - 1;
	if (!set || !s1)
		return (0);
	while (ft_strchr((char *)set, s1[start]))
		start++;
	while (ft_strchr((char *)set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
