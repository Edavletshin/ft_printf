/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:42:11 by galiza            #+#    #+#             */
/*   Updated: 2019/07/14 14:56:29 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		if_minus(t_flags flags, int len, const char *s, int strlen)
{
	if (flags.minus)
	{
		if (flags.t_dot > 0)
			ft_putnstr(s, flags.t_dot);
		else
			ft_putstr(s);
		len += ft_print_spaces(flags, strlen);
	}
	else
	{
		len += ft_print_spaces(flags, strlen);
		if (flags.t_dot > 0)
			ft_putnstr(s, flags.t_dot);
		else
			ft_putstr(s);
	}
	return (len);
}

int				print_miss(t_flags flags, int len, int strlen)
{
	len += ft_print_spaces(flags, strlen);
	return (len);
}

int				ft_print_s(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags		flags;
	const char	*s;
	int			strlen;

	strlen = 0;
	ft_get_keys(fmt, curr_chr, &flags);
	s = va_arg(ap, const char *);
	if (flags.t_dot < 0)
	{
		len += print_miss(flags, len, 0);
		return (ft_printf_aux(fmt, ap, curr_chr
		+ flags.len + 1, len + strlen));
	}
	if (s == NULL)
		s = "(null)";
	strlen = ft_strlen(s);
	if (strlen > flags.t_dot && flags.t_dot > 0)
		strlen = flags.t_dot;
	else
		flags.t_dot = 0;
	if (if_long(fmt, curr_chr, flags))
		flags.zero = 1;
	len = if_minus(flags, len, s, strlen);
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1,
				len + strlen));
}

int				print_o_norminnet(t_flags flags, int len,
				unsigned long long int n)
{
	if (flags.h_tag && n)
	{
		ft_putchar('0');
		len++;
	}
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr_base(ABS(n), 8, "01234567");
	if (flags.dot && !n && flags.h_tag)
	{
		ft_putchar('0');
		len++;
	}
	len = print_miss((flags), len, 0);
	return (len);
}

int				print_o_norm(t_flags *flags_r, int s, unsigned long long int n)
{
	(*flags_r).un_tot = n;
	(*flags_r).plus = 0;
	s = ft_get_len(*flags_r);
	return (s);
}
