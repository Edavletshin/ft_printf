/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:20:54 by galiza            #+#    #+#             */
/*   Updated: 2019/05/18 19:23:30 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base(int n, unsigned int base, const char *digits)
{
	long long int	num;
	int				res;

	res = 1;
	if (n < 0)
	{
		res++;
		ft_putchar('-');
		num = (long long int)-n;
	}
	else
		num = (long long int)n;
	if (num >= base)
		res += ft_putnbr_base(num / base, base, digits);
	ft_putchar(digits[n % base]);
	return (res);
}

int		ft_putnbr(int n)
{
	long long int	num;
	int				res;

	res = 1;
	if (n < 0)
	{
		res++;
		ft_putchar('-');
		num = (long long int)-n;
	}
	else
		num = (long long int)n;
	if (num >= 10)
		res += ft_putnbr(num / 10);
	ft_putchar(n % 10 + '0');
	return (res) ;
}
