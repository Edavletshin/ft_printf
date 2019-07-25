/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:55:29 by galiza            #+#    #+#             */
/*   Updated: 2019/06/20 15:53:37 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			if_all(t_flags flags, int s, int len, long long int c)
{
	if (flags.minus == 0)
	{
		len += ft_print_spaces(flags, s);
		ft_putstr("0x");
		len += ft_putnbr_base(c, 16, "0123456789abcdef") + 2;
	}
	else
	{
		ft_putstr("0x");
		len += ft_putnbr_base(c, 16, "0123456789abcdef") + 2;
		len += ft_print_spaces(flags, s);
	}
	return (len);
}

int					ft_print_p(const char *fmt, va_list ap,
					int curr_chr, int len)
{
	t_flags			flags;
	long long int	c;
	int				s;

	ft_get_keys(fmt, curr_chr, &flags);
	if (flags.t_dot < 0)
	{
		ft_putstr("0x");
		len = print_miss(flags, len, 0);
		len += 2;
		return (ft_printf_aux(fmt, ap, curr_chr + flags.len +
		1, len));
	}
	c = va_arg(ap, long long int);
	s = ft_putun_nbr_base_not_print(c, 16, "0123456789abcdef") + 2;
	len = if_all(flags, s, len, c);
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}

void				print_u_norm(t_flags *flags, unsigned long long int n)
{
	(*flags).un_tot = n;
	(*flags).plus = 0;
	(*flags).blank = 0;
}
