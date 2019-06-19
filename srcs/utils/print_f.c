/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:20:04 by galiza            #+#    #+#             */
/*   Updated: 2019/06/09 21:15:13 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	if_n(t_flags flags, va_list ap)
{
	double		n;

	if (flags.flags & LL)
		n = va_arg(ap, double);
	else if (flags.flags & L)
		n = va_arg(ap, double);
	else
		n = va_arg(ap, double);
	return (n);
}

static int		if_zero(t_flags flags, int len, int accur, double n)
{
	int			s;

	s = size(n);
	if (n < 0 || flags.plus)
		s++;
	len += ft_print_keys(flags, s);
	len += ft_print_spaces(flags, s + accur + 1);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putnbr(ABS(n));
	len += ft_print_accur(flags, accur);
	return (len);
}

static int		if_minus(t_flags flags, int len, int accur, double n)
{
	int			s;

	s = size(n);
	if (n < 0 || flags.plus)
		s++;
	if (flags.minus)
	{
		len += ft_print_keys(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr(ABS(n));
		len += ft_print_accur(flags, accur);
		len += ft_print_spaces(flags, s + accur + 1);
	}
	else if (flags.zero)
		len = if_zero(flags, len, accur, n);
	else
	{
		len += ft_print_spaces(flags, s + accur + 1);
		len += ft_print_keys(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr(ABS(n));
		len += ft_print_accur(flags, accur);
	}
	return (len);
}

int				if_long(const char *fmt, int curr_chr, t_flags flags)
{
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr
	+ flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
	fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && !flags.dot &&
		flags.padding > 0)
		return (1);
	else
		return (0);
}

int				ft_print_f(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags		flags;
	double		n;
	int			accur;

	ft_get_keys(fmt, curr_chr, &flags);
	if (flags.t_dot <= 0 && flags.t_dot != -1)
		accur = 6;
	else
	{
		if (flags.t_dot == -1)
			accur = 0;
		else
			accur = flags.t_dot;
		flags.t_dot = 0;
	}
	n = if_n(flags, ap);
	flags.flt = n;
	if (if_long(fmt, curr_chr, flags))
		flags.zero = 1;
	len = if_minus(flags, len, accur, n);
	len += print_fract(n, len, accur);
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len + accur));
}
