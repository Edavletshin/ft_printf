/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:20:04 by galiza            #+#    #+#             */
/*   Updated: 2019/05/29 18:03:09 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		un_size(unsigned long long int i)
{
	int	tmp;

	tmp = 0;
	if (!i)
		return (0);
	while ((i /= 10) != 0)
		tmp++;
	return (tmp + 1);
}

int		ft_print_u(const char *fmt, va_list ap, int curr_chr, int len)
{
	t_flags					flags;
	int						s;
	unsigned long long int	n;

	ft_get_keys(fmt, curr_chr, &flags);
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
	s = un_size(n);
	flags.un_tot = n;
	flags.plus = 0;
	if (((fmt[curr_chr + flags.l_int] == '0' && ft_atoi(fmt + curr_chr
+ flags.l_int) != 0) || (fmt[curr_chr + flags.l_int - 1] == '+' &&
fmt[curr_chr + flags.l_int - 2] == '0')) && !flags.minus && !flags.dot &&
		flags.padding > 0)
		flags.zero = 1;
	if (flags.minus)
	{
		len += ft_print_keys(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putun_nbr(ABS(n));
		len += ft_print_spaces(flags, s);
	}
	else if (flags.zero)
	{
		len += ft_print_keys(flags, s);
		len += ft_print_spaces(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putun_nbr(ABS(n));
	}
	else
	{
		len += ft_print_spaces(flags, s);
		len += ft_print_keys(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putun_nbr(ABS(n));
	}
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
