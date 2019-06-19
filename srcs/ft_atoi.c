/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:06:27 by galiza            #+#    #+#             */
/*   Updated: 2019/05/25 15:04:00 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	return (ft_atoi_base(str, 10));
}

int		set_total(const char *str, int i, int total, int base)
{
	if (str[i] <= 70 && str[i] >= 65)
		total = total * base + str[i] - 'A' + 10;
	else if (str[i] >= 'a' && str[i] <= 'f')
		total = total * base + str[i] - 'a' + 10;
	else if (base < 10)
		total = total * base + str[i] - 48 + 10 - base;
	else
		total = total * base + str[i] - 48;
	return (total);
}

int		set_length_to_int(const char *str, int *minus)
{
	int	i;

	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] >= 32 && str[i] <= 44))
		i++;
	if (str[i] == '-')
		*minus = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

int		ft_atoi_base(const char *str, int base)
{
	long long	i;
	long		total;
	int			minus;

	minus = 0;
	i = 0;
	total = 0;
	i = set_length_to_int(str, &minus);
	while ((str[i] >= 48 && str[i] <= 57) ||
			(str[i] + (base - 15) > 'A' && str[i] + (15 - base) < 'F')
			|| (str[i] + (base - 15) > 'a' && str[i] + (15 - base) < 'f'))
	{
		total = set_total(str, i, total, base);
		if (total < 0 && minus)
			return (0);
		else if (total < 0 && !minus)
			return (-1);
		i++;
	}
	if (minus)
		return (-total);
	return (total);
}
