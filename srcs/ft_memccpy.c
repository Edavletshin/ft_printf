/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:21:34 by galiza            #+#    #+#             */
/*   Updated: 2019/04/06 16:15:48 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	void	*p;

	p = ft_memchr(source, c, n);
	if (p != 0)
	{
		return ((ft_memcpy(destination, source,
						p - source + 1) + (p - source + 1)));
	}
	ft_memcpy(destination, source, n);
	return (0);
}
