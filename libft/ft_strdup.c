/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:31:25 by horandri          #+#    #+#             */
/*   Updated: 2024/12/20 15:56:39 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*duplicate;

	if (str == NULL)
		return(NULL);
	len = ft_strlen(str) + 1;
	duplicate = malloc(len * sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, len);
	return (duplicate);
}

char	*ft_strdup_free(char *str)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(str) + 1;
	duplicate = malloc(len * sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, len);
	free(str);
	return (duplicate);
}
