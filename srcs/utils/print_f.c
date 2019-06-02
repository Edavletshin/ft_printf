/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:20:04 by galiza            #+#    #+#             */
/*   Updated: 2019/05/31 15:05:34 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_f(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags			flags;
	int				s;
	double			n;
	int				accur;

	ft_get_keys(fmt, curr_chr, &flags);
	accur = flags.t_dot;
	flags.t_dot = 0;
	if (flags.flags & LL)
		n = va_arg(ap, double);
	else if (flags.flags & L)
		n = va_arg(ap, double);
	else
		n = va_arg(ap, double);
	s = size(n);
	flags.flt = n;
	if (n < 0 || flags.plus)
		s++;
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr
+ flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && !flags.dot &&
		flags.padding > 0)
		flags.zero = 1;
	if (flags.minus)
	{
		len += ft_print_keys(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr(ABS(n));
		len += ft_print_accur(flags, accur);
		len += ft_print_spaces(flags, s);
	}
	else if (flags.zero)
	{
		len += ft_print_keys(flags, s);
		len += ft_print_spaces(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr(ABS(n));
		len += ft_print_accur(flags, accur);
	}
	else
	{
		len += ft_print_spaces(flags, s);
		len += ft_print_keys(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr(ABS(n));
		len += ft_print_accur(flags, accur);
	}
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
