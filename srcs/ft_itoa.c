/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:39:44 by galiza            #+#    #+#             */
/*   Updated: 2019/04/10 20:49:20 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		set_all(char *total, int n, int size)
{
	int		i;

	i = 0;
	if (n < 0)
		total[i++] = '-';
	while (size)
	{
		if (n < 0)
			total[i] = n / size * -1 + 48;
		else
			total[i] = n / size + 48;
		n %= size;
		size /= 10;
		i++;
	}
	total[i] = '\0';
}

char			*ft_itoa(int n)
{
	char		*total;
	long long	temp;
	long long	size;
	int			i;

	size = 1;
	temp = n;
	i = 0;
	while ((temp /= 10) != 0)
	{
		i++;
		size *= 10;
	}
	if (!(total = ft_strnew(i + 1 + (n < 0))))
		return (0);
	set_all(total, n, size);
	return (total);
}
