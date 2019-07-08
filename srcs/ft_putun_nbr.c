/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:20:54 by galiza            #+#    #+#             */
/*   Updated: 2019/06/10 14:50:31 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putun_nbr_base(unsigned long long int n, unsigned int base,
		const char *digits)
{
	int						res;

	res = 1;
	if (n >= base)
		res += ft_putun_nbr_base(n / base, base, digits);
	ft_putchar(digits[n % base]);
	return (res);
}

int		ft_putun_nbr(unsigned long long int n)
{
	return (ft_putun_nbr_base(n, 10, "0123456789"));
}

int		ft_putun_nbr_base_not_print(unsigned long long int n, unsigned int base,
							 const char *digits)
{
	int						res;

	res = 1;
	if (n >= base)
		res += ft_putun_nbr_base_not_print(n / base, base, digits);
	return (res);
}
