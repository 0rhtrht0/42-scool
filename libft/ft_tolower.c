/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:32:51 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:52 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int e)
{
	if (e >= 65 && e <= 90)
	{
		e = e + 32;
	}
	return (e);
}
