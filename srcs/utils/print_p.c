/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:55:29 by galiza            #+#    #+#             */
/*   Updated: 2019/05/29 14:18:17 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_p(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags			flags;
	long long int	c;

	ft_get_keys(fmt, curr_chr, &flags);
	c = va_arg(ap, long long int);
	ft_putstr("0x");
	len += ft_putnbr_base(c, 16, "0123456789abcdef") + 2;
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
