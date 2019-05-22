/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:19:36 by galiza            #+#    #+#             */
/*   Updated: 2019/04/11 21:56:27 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	int i;

	i = 0;
	if (!destination && !source)
		return (NULL);
	while (i < (int)n)
	{
		((unsigned char*)destination)[i] = ((unsigned char*)source)[i];
		i++;
	}
	return (destination);
}
