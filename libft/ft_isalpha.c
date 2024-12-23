/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horandri <horandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:29:20 by horandri          #+#    #+#             */
/*   Updated: 2024/07/29 14:29:21 by horandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int e)
{
	int	r;

	r = 0;
	if ((e >= 65 && e <= 90) || (e >= 97 && e <= 122))
		r = 1;
	return (r);
}
