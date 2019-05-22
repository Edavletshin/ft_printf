/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:58:59 by galiza            #+#    #+#             */
/*   Updated: 2019/04/11 20:57:55 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(s);
	temp = (char *)s + len;
	while (len + 1)
	{
		if (*temp == (char)c)
			return (temp);
		len--;
		temp--;
	}
	return (0);
}
