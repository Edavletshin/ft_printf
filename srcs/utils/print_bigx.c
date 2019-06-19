/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:18:37 by galiza            #+#    #+#             */
/*   Updated: 2019/06/09 20:03:06 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int						if_flags_else(t_flags flags, int len,
		unsigned long long int n, int s)
{
	len += ft_print_spaces(flags, s);
	if (flags.h_tag && flags.un_tot)
	{
		ft_putstr("0X");
		len += 2;
	}
	len += ft_print_keys(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr_base(ABS(n), 16, "0123456789ABCDEF");
	return (len);
}

static int						if_flags_zero(t_flags flags, int len,
		unsigned long long int n, int s)
{
	if (flags.h_tag && flags.un_tot)
	{
		ft_putstr("0X");
		len += 2;
	}
	len += ft_print_keys(flags, s);
	len += ft_print_spaces(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr_base(ABS(n), 16, "0123456789ABCDEF");
	return (len);
}

static int						if_flags_minus(t_flags flags, int len,
		unsigned long long int n, int s)
{
	if (flags.minus)
	{
		if (flags.h_tag && flags.un_tot)
		{
			ft_putstr("0X");
			len += 2;
		}
		len += ft_print_keys(flags, s);
		if (flags.dot > 0 || (n != 0) || !flags.dot)
			len += ft_putun_nbr_base(ABS(n), 16, "0123456789ABCDEF");
		len += ft_print_spaces(flags, s);
	}
	else if (flags.zero)
	{
		len = if_flags_zero(flags, len, n, s);
	}
	else
	{
		len = if_flags_else(flags, len, n, s);
	}
	return (len);
}

static unsigned long long int	if_n(t_flags flags, va_list ap)
{
	unsigned long long int		n;

	if (flags.flags & LL)
		n = va_arg(ap, unsigned long long int);
	else if (flags.flags & L)
		n = va_arg(ap, unsigned long long int);
	else if (flags.flags & H && !(flags.flags & HH))
		n = (unsigned short int)va_arg(ap, int);
	else if (flags.flags & HH)
		n = (unsigned char)va_arg(ap, int);
	else
		n = va_arg(ap, unsigned int);
	return (n);
}

int								ft_print_bigx(const char *fmt,
		va_list ap, int curr_chr, int len)
{
	t_flags						flags;
	int							s;
	unsigned long long int		n;

	ft_get_keys(fmt, curr_chr, &flags);
	n = if_n(flags, ap);
	s = size(n);
	flags.un_tot = n;
	if (flags.plus)
		s++;
	if (flags.h_tag)
		s += 2;
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr +
	flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
	fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && !flags.dot &&
		flags.padding > 0)
		flags.zero = 1;
	len = if_flags_minus(flags, len, n, s);
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
