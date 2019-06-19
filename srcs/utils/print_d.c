/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:20:04 by galiza            #+#    #+#             */
/*   Updated: 2019/06/19 21:07:12 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	if_n(t_flags flags, va_list ap)
{
	long long int		n;

	if (flags.flags & LL)
		n = va_arg(ap, long long int);
	else if (flags.flags & L)
		n = va_arg(ap, long long int);
	else if (flags.flags & H && !(flags.flags & HH))
		n = (short int)va_arg(ap, int);
	else if (flags.flags & HH)
		n = (signed char)va_arg(ap, int);
	else
		n = (int)va_arg(ap, int);
	return (n);
}

static int				if_zero(t_flags flags, int len, int s, long long int n)
{
	len += ft_print_keys(flags, s);
	len += ft_print_spaces(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putnbr(ABS(n));
	return (len);
}

static int				if_else(t_flags flags, int len, int s, long long int n)
{
	len += ft_print_spaces(flags, s);
	len += ft_print_keys(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putnbr(ABS(n));
	return (len);
}

static int				if_minus(t_flags flags, int len, int s, long long int n)
{
	len += ft_print_keys(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putnbr(ABS(n));
	len += ft_print_spaces(flags, s);
	return (len);
}

int						ft_print_d(const char *fmt, va_list ap,
						int curr_chr, int len)
{
	t_flags				flags;
	int					s;
	long long int		n;

	ft_get_keys(fmt, curr_chr, &flags);
	n = if_n(flags, ap);
	s = ft_get_len(flags);
	flags.total = n;
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr +
	flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
	fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && !flags.dot &&
		flags.padding > 0)
		flags.zero = 1;
	if (flags.minus)
		len = if_minus(flags, len, s, n);
	else if (flags.zero)
		len = if_zero(flags, len, s, n);
	else
		len = if_else(flags, len, s, n);
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
