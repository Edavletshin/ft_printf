/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:18:20 by galiza            #+#    #+#             */
/*   Updated: 2019/04/12 18:31:16 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, int (*f) (char*))
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			counter++;
		i++;
	}
	return (counter);
}
