/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:32:48 by galiza            #+#    #+#             */
/*   Updated: 2019/05/29 14:19:39 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_c(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags	flags;
	int		c;

	ft_get_keys(fmt, curr_chr, &flags);
	flags.t_dot = 0;
	c = va_arg(ap, int);
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr
+ flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && flags.padding > 0)
		flags.zero = 1;
	if (flags.minus)
	{
		ft_putchar(c);
		len += ft_print_spaces(flags, 1);
	}
	else
	{
		len += ft_print_spaces(flags, 1);
		ft_putchar(c);
	}
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len + 1));
}
