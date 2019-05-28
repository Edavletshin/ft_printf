/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:42:11 by galiza            #+#    #+#             */
/*   Updated: 2019/05/28 22:28:33 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_s(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags		flags;
	const char	*s;
	int			strlen;

	strlen = 0;
	ft_get_keys(fmt, curr_chr, &flags);
	s = va_arg(ap, const char *);
	if (s == NULL)
		s = "(null)";
	strlen = ft_strlen(s);
	if (strlen > flags.t_dot && flags.t_dot > 0)
		strlen = flags.t_dot;
	else
		flags.t_dot = 0;
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr
+ flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && flags.padding > 0)
	   flags.zero = 1;
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
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1,
				len + strlen));
}
