/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:20:54 by galiza            #+#    #+#             */
/*   Updated: 2019/05/28 20:41:50 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base(long long int n, int base, const char *digits)
{
	long long int	num;
	int				res;

	num = 0;
	res = 1;
	if (n < 0)
	{
		res++;
		ft_putchar('-');
		num = (num + n) * -1;
	}
	else
		num = n;
	if (num >= base)
		res += ft_putnbr_base(num / base, base, digits);
	else if (num < 0)
		res += ft_putnbr_base(num / base * -1, base, digits);
	if (num < 0)
		ft_putchar(digits[num % base * -1]);
	else
		ft_putchar(digits[num % base]);
	return (res);
}

int		ft_putnbr(long long int n)
{
	return (ft_putnbr_base(n, 10, "0123456789"));
}
