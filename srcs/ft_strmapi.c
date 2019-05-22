/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:29:59 by galiza            #+#    #+#             */
/*   Updated: 2019/04/10 16:20:11 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (!(temp = ft_strdup(s)))
		return (0);
	while (s[i])
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	return (temp);
}
