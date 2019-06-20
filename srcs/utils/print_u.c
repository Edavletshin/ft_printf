/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:20:04 by galiza            #+#    #+#             */
/*   Updated: 2019/06/20 15:10:19 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int								un_size(unsigned long long int i)
{
	int							tmp;

	tmp = 0;
	while ((i /= 10) != 0)
		tmp++;
	return (tmp + 1);
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

static int						if_minus(t_flags flags, int len, int s,
								unsigned long long int n)
{
	len += ft_print_keys(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr(ABS(n));
	len += ft_print_spaces(flags, s);
	return (len);
}

static int						if_zero(t_flags flags, int len, int s,
								unsigned long long int n)
{
	len += ft_print_keys(flags, s);
	len += ft_print_spaces(flags, s);
	if (flags.t_dot > 0 || (n != 0) || !flags.dot)
		len += ft_putun_nbr(ABS(n));
	return (len);
}

int								ft_print_u(const char *fmt, va_list ap,
								int curr_chr, int len)
{
	t_flags						flags;
	int							s;
	unsigned long long int		n;

	ft_get_keys(fmt, curr_chr, &flags);
	n = if_n(flags, ap);
	flags.un_tot = n;
	flags.plus = 0;
	flags.blank = 0;
	s = ft_get_len(flags);
	if (if_long(fmt, curr_chr, flags))
		flags.zero = 1;
	if (flags.minus)
		len = if_minus(flags, len, s, n);
	else if (flags.zero)
		len = if_zero(flags, len, s, n);
	else
	{
		len += ft_print_spaces(flags, s);
		len += ft_print_keys(flags, s);
		if (flags.t_dot > 0 || (n != 0) || !flags.dot)
			len += ft_putun_nbr(ABS(n));
	}
	return (ft_printf_aux(fmt, ap, curr_chr + flags.len + 1, len));
}
