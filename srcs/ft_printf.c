/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:28:51 by galiza            #+#    #+#             */
/*   Updated: 2019/05/28 20:58:39 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* *************************** */
/*        print -e             */
/* *************************** */

int		ft_print_e(const char *fmt, va_list ap, int len)
{
	double		n;
	long int	tmp;

	n = va_arg(ap, double);
	tmp = (long int)n;
	len += ft_putnbr(tmp);
	ft_putchar('.');
	len++;
	n -= tmp;
	n *= 100000;
	//printf("\n%ld\n", tmp);
	len += ft_putnbr((int)(n + 0.5));
	return (ft_printf_aux(fmt, ap, 0, len));
}

/* *************************** */
/*         print octal         */
/* *************************** */

int		ft_print_o(const char *fmt, va_list ap, int len)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	len += ft_putnbr_base(n, 8, "01234567");
	return (ft_printf_aux(fmt, ap, 0, len));
}

/* *************************** */
/*      print insigned int     */
/* *************************** */

int		ft_print_u(const char *fmt, va_list ap, int len)
{
	unsigned int n;

	n = va_arg(ap, unsigned int);
	len += ft_putnbr(n);
	return (ft_printf_aux(fmt, ap, 0, len));
}

/* *************************** */
/*          print hex          */
/* *************************** */

int		ft_print_x(const char *fmt, va_list ap, int len)
{
	unsigned int n;

	n = va_arg(ap, unsigned int);
	len += ft_putnbr_base(n, 16, "0123456789abcdef");
	return (ft_printf_aux(fmt, ap, 0, len));
}

/* *************************** */
/*        print big hex        */
/* *************************** */

int		ft_print_bigx(const char *fmt, va_list ap, int len)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	len += ft_putnbr_base(n, 16, "0123456789ABCDEF");
	return (ft_printf_aux(fmt, ap, 0, len));
}

/* *************************** */
/*        print length         */
/* *************************** */

int		ft_print_numb(const char *fmt, va_list ap, int len)
{
	int		*n;

	n = va_arg(ap, int*);
	*n = len;
	return (ft_printf_aux(fmt, ap, 0, len));
}

typedef int (*ft_print_dispatch_f)(const char *fmt, va_list ap, int
		curr_chr, int len);

static	ft_print_dispatch_f const ft_print_dispatch[256] =
{
	['c'] = ft_print_c,
	['s'] = ft_print_s,
//	['p'] = ft_print_s,
//	['f'] = ft_print_d,
	['d'] = ft_print_d,
//	['i'] = ft_print_d,
//	['o'] = ft_print_o,
//	['u'] = ft_print_u,
//	['x'] = ft_print_x,
//	['X'] = ft_print_bigx,
};

int		ft_printf_aux(const char *fmt, va_list v_l, int curr_chr, int len)
{
	int		c;
	int		i;

	i = 0;
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
			while (ft_strchr("#-+*.lh 0123456789", fmt[curr_chr + i]))
				c = (unsigned char)(fmt[curr_chr + ++i]);
			c = (unsigned char)(fmt[curr_chr + i]);
			if (ft_print_dispatch[c] == NULL)
			{
				if (c == '\0')
					break;
				c = (unsigned char)(fmt[curr_chr]);
				ft_putchar(c);
				curr_chr++;
				len++;
			}
			else if (c == '%')
			{
				ft_putchar('%');
				curr_chr++;
				len++;
			}
			else
				return ft_print_dispatch[c](fmt, v_l, curr_chr, len);
		}
		i = 0;
	}
	return (len);
}

int		ft_vprintf(const char *fmt, va_list ap)
{
	    return (ft_printf_aux(fmt, ap, 0, 0));
}

int		ft_printf(const char *format, ...)
{
	va_list v_l;
	int total;

	va_start(v_l, format);
	total = ft_printf_aux(format, v_l, 0, 0);
	va_end(v_l);
	return (total);
}
