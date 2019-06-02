/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:18:37 by galiza            #+#    #+#             */
/*   Updated: 2019/05/29 15:46:21 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_o(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags			flags;
	int				s;
	long long int	n;

	ft_get_keys(fmt, curr_chr, &flags);
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
	s = size(n);
	flags.total = n;
	if (n < 0 || flags.plus || flags.h_tag)
		s++;
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr
+ flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
	fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && !flags.dot &&
		flags.padding > 0)
		flags.zero = 1;
	if (flags.minus)
	{							
		len += ft_print_keys(flags, s);
		if (flags.h_tag)
		{
			ft_putchar('0');
			len++;
		}
		if (flags.dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr_base(ABS(n), 8, "01234567");
		len += ft_print_spaces(flags, s);
	}
	else if (flags.zero)
	{
		len += ft_print_keys(flags, s);
		len += ft_print_spaces(flags, s);
		if (flags.h_tag)
		{
			ft_putchar('0');
			len++;
		}
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr_base(ABS(n), 8, "01234567");
	}
	else
	{
		len += ft_print_spaces(flags, s);
		len += ft_print_keys(flags, s);
		if (flags.h_tag)
		{
			ft_putchar('0');
			len++;
		}
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putnbr_base(ABS(n), 8, "01234567");
	}
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
