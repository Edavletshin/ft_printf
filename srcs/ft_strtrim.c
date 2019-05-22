/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:34:33 by galiza            #+#    #+#             */
/*   Updated: 2019/04/13 16:56:21 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	char	*str;

	if (!s)
		return (0);
	len = ft_strlen(s) - 1;
	start = 0;
	while (s[start] &&
			(s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
		start++;
	while (len &&
			(s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	if (!(str = ft_strsub(s, start, len > start ? len - start + 1 : 0)))
		return (0);
	return (str);
}
