/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:19:45 by galiza            #+#    #+#             */
/*   Updated: 2019/04/12 18:28:45 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	long int min;
	long int max;

	min = 0;
	max = nb;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (max - min > 1)
	{
		if ((((min + max) / 2) * ((min + max) / 2)) == nb)
			return ((min + max) / 2);
		if ((((min + max) / 2) * ((min + max) / 2)) < nb)
			min = (min + max) / 2;
		else
			max = (min + max) / 2;
	}
	return (0);
}
