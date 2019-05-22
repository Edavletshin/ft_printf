/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:28:51 by galiza            #+#    #+#             */
/*   Updated: 2019/05/22 17:24:35 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* *************************** */
/*        print integer        */
/* *************************** */

int		ft_print_d(const char *fmt, va_list ap, int len)
{
	int	n;

	n = va_arg(ap, int);
	len += ft_putnbr(n);
	return (ft_printf_aux(fmt, ap, 0, len));
}

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
/*        print string         */
/* *************************** */

int		ft_print_s(const char *fmt, va_list ap, int len)
{
	const char *s;

	s = va_arg(ap, const char *);
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s++);
		len++;
	}
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

typedef int (*ft_print_dispatch_f)(const char *fmt, va_list ap, int len);

static	ft_print_dispatch_f const ft_print_dispatch[256] =
{
	['c'] = ft_print_c,
	['d'] = ft_print_d,
	['i'] = ft_print_d,
	['e'] = ft_print_e,
	['E'] = ft_print_d,
	['f'] = ft_print_d,
	['g'] = ft_print_d,
	['G'] = ft_print_d,
	['o'] = ft_print_o,
	['s'] = ft_print_s,
	['u'] = ft_print_u,
	['x'] = ft_print_x,
	['X'] = ft_print_bigx,
	['p'] = ft_print_s,
	['n'] = ft_print_numb,
};

int		ft_printf_aux(const char *format, va_list v_l, int len,
		int curr_chr)
{
	int		c;
	int		i;

	i = 0;
	while (format[curr_chr])
	{
		c = (unsigned char)format[curr_chr++];
		if (c != '%')
			ft_putchar(c);
		else
		{
			c = (unsigned char)format[curr_chr];
			while (c == '.' || c == '-' || c == '+' ||
					c == '*' || (c >= '0' && c <= '9'))
				c = (unsigned char)(format[curr_chr + i++]);
			if (ft_print_dispatch[c] == NULL)
			{
				if (c == '\0')
					break;
				ft_putchar(c);
				len++;
			}
			else if (c == '%')
			{
				ft_putchar('%');
				len++;
			}
			else
				return ft_print_dispatch[c](format, v_l, curr_chr);
		}
		i = 0;
	}
	return (len);
}

int		ft_vprintf(const char *fmt, va_list ap) {
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
