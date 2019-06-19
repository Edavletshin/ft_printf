/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:55:53 by galiza            #+#    #+#             */
/*   Updated: 2019/04/10 15:31:53 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	lens2;
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)s1;
	lens2 = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*temp && i + lens2 <= len)
	{
		if (!ft_strncmp(temp, s2, lens2))
			return (temp);
		temp++;
		i++;
	}
	return (0);
}
