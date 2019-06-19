/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:34:44 by galiza            #+#    #+#             */
/*   Updated: 2019/04/12 16:06:12 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstlen >= size)
		return (srclen + size);
	while (dstlen + i < size - 1 && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	while (dstlen + i < size)
		dst[dstlen + i++] = '\0';
	return (dstlen + srclen);
}
