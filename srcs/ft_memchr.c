/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:05:48 by galiza            #+#    #+#             */
/*   Updated: 2019/04/11 19:33:26 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*point;
	int				i;

	i = 0;
	point = (unsigned char*)arr;
	while (i < (int)n)
	{
		if (((unsigned char*)arr)[i] == ((unsigned char)c))
			return ((void *)point);
		point++;
		i++;
	}
	return (0);
}
