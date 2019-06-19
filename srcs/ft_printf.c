/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:28:51 by galiza            #+#    #+#             */
/*   Updated: 2019/06/10 14:35:43 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef int	(*t_ft_print_dispatch_f)(const char *fmt, va_list ap, int
		curr_chr, int len);

static	t_ft_print_dispatch_f const g_ft_print_dispatch[256] =
{
	['%'] = ft_print_percent,
	['c'] = ft_print_c,
	['s'] = ft_print_s,
	['p'] = ft_print_p,
	['f'] = ft_print_f,
	['d'] = ft_print_d,
	['i'] = ft_print_d,
	['o'] = ft_print_o,
	['u'] = ft_print_u,
	['x'] = ft_print_x,
	['X'] = ft_print_bigx,
};

void	function(t_flags flags, int *curr_chr, const char *fmt, int *len)
{
	if (flags.padding > 0)
	{
		curr_chr += flags.len + 1;
		*len = *len + ft_print_spaces(flags, 0);
	}
	else
	{
		ft_putchar(fmt[*curr_chr]);
		*curr_chr = *curr_chr + 1;
		*len = *len + 1;
	}
}

int		ft_printf_aux(const char *fmt, va_list v_l, int curr_chr, int len)
{
	t_flags	flags;
	int		c;

	while (fmt[curr_chr])
	{
		c = (unsigned char)fmt[curr_chr++];
		if (c != '%')
		{
			len++;
			ft_putchar(c);
		}
		else
		{
			ft_get_keys(fmt, curr_chr, &flags);
			c = (unsigned char)(fmt[curr_chr + flags.len]);
			if (c == '\0')
				break ;
			if (g_ft_print_dispatch[c] == NULL)
				function(flags, &curr_chr, fmt, &len);
			else
				return (g_ft_print_dispatch[c](fmt, v_l, curr_chr, len));
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	v_l;
	int		total;

	va_start(v_l, format);
	total = ft_printf_aux(format, v_l, 0, 0);
	va_end(v_l);
	return (total);
}
