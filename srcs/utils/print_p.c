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

int		ft_print_p(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags			flags;
	long long int	c;
	int				s;

	ft_get_keys(fmt, curr_chr, &flags);
	c = va_arg(ap, long long int);
	s = ft_putun_nbr_base_not_print(c, 16, "0123456789abcdef") + 2;
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
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}


int		ft_get_len_x(t_flags flags)
{
	int	tmp;
	int	i;

	i = 0;
	if (flags.total < 0 || 1 / flags.flt < 0)
		i = 1;
	else if (flags.plus)
		i = 1;
	else if (flags.blank)
		i = 1;
	tmp = size_x(flags.total) > un_size_x(flags.un_tot) ? size_x(flags.total) :
		  un_size_x(flags.un_tot);
	tmp -= !(flags.t_dot > 0 || (flags.total != 0
								 || flags.un_tot != 0) || !flags.dot);
	flags.t_dot = flags.t_dot - tmp;
	if (flags.t_dot < 0)
		flags.t_dot = 0;
	return (flags.t_dot + i + tmp);
}

int		un_size_x(unsigned long long int i)
{
	int	tmp;

	tmp = 0;
	while ((i /= 16) != 0)
		tmp++;
	return (tmp + 1);
}

int			size_x(long long int i)
{
	int		tmp;

	tmp = 0;
	while ((i /= 16) != 0)
		tmp++;
	return (tmp + 1);
}