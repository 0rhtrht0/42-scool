/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:45 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:29:46 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int e)
{
	int	r;

	r = 0;
	if (e >= 48 && e <= 57)
		r = 1;
	return (r);
}