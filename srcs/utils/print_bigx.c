/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:18:37 by galiza            #+#    #+#             */
/*   Updated: 2019/07/24 18:39:19 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int						if_minus(t_flags flags, int len, int s,
								unsigned long long int n)
{
	if (flags.h_tag && flags.un_tot)
	{
		ft_putstr("0X");
		len += 2;
	}
	len += ft_print_keys(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr_base(ABS(n), 16, "0123456789ABCDEF");
	len += ft_print_spaces(flags, s);
	return (len);
}

static int						if_zero(t_flags flags, int len, int s,
								unsigned long long int n)
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

static int						if_else(t_flags flags, int len, int s,
								unsigned long long int n)
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

int								ft_print_bigx(const char *fmt, va_list ap,
								int curr_chr, int len)
{
	t_flags						flags;
	int							s;
	unsigned long long int		n;

	ft_get_keys(fmt, curr_chr, &flags);
	if (flags.t_dot < 0)
		return (ft_printf_aux(fmt, ap, curr_chr
		+ flags.len + 1, print_miss(flags, len, 0)));
		flags.base = 16;
	n = if_n(flags, ap);
	flags.un_tot = n;
	s = ft_get_len(flags);
	if (flags.plus)
		s++;
	if (flags.h_tag && flags.un_tot)
		s += 2;
	if (if_long(fmt, curr_chr, flags) && !flags.dot)
		flags.zero = 1;
	if (flags.minus)
		len = if_minus(flags, len, s, n);
	else if (flags.zero)
		len = if_zero(flags, len, s, n);
	else
		len = if_else(flags, len, s, n);
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
