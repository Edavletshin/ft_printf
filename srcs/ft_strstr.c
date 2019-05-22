/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:31:18 by galiza            #+#    #+#             */
/*   Updated: 2019/04/10 15:45:48 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;
	char	*temp;

	temp = (char *)s1;
	len = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*temp)
	{
		if (!ft_strncmp(temp, s2, len))
			return (temp);
		temp++;
	}
	return (0);
}
