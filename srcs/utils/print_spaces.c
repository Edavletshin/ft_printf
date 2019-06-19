/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:56:29 by galiza            #+#    #+#             */
/*   Updated: 2019/06/19 21:07:10 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_accur(t_flags flags, int accur)
{
	int	tmp;
	int	size;
	int	len;

	size = 10;
	len = 0;
	tmp = (int)flags.flt;
	flags.flt -= (float)tmp;
	flags.flt = ABS(flags.flt);
	if (accur)
	{
		ft_putchar('.');
		len++;
	}
	return (len);
}

int		ft_print_spaces(t_flags flags, int size_int)
{
	int	tmp;
	int	width;

	width = ABS(flags.padding) - size_int;
	if (width < 0)
		width = 0;
	tmp = width;
	while (tmp-- > 0)
		flags.zero ? ft_putchar('0') : ft_putchar(' ');
	return (width);
}

void	ft_get_int(const char *fmt, int curr_chr, t_flags *flags)
{
	int	i;

	i = (*flags).len;
	while ((fmt[curr_chr + i] < '1' || fmt[curr_chr + i] > '9') && i > 0)
		i--;
	while (((fmt[curr_chr + i] >= '0' && fmt[curr_chr + i] <= '9')
			|| fmt[curr_chr + i] == '.') && fmt[curr_chr + i])
		i--;
	i++;
	(*flags).l_int = i;
}

int		ft_print_keys(t_flags flags, int size_int)
{
	int	i;

	i = 0;
	size_int = 0;
	if ((flags.total < 0 && ABS(flags.total) > 0) || 1 / flags.flt < 0)
	{
		ft_putchar('-');
		i = 1;
	}
	else if (flags.plus && flags.total >= 0)
	{
		ft_putchar('+');
		i = 1;
	}
	else if (flags.blank && flags.total >= 0)
	{
		ft_putchar(' ');
		i = 1;
	}
	flags.t_dot -= size(flags.total) + !(flags.t_dot > 0 || (flags.total != 0) || !flags.dot);
	if (flags.t_dot < 0)
		flags.t_dot = 0;
	i += flags.t_dot;
	while (flags.t_dot-- > 0)
		ft_putchar('0');
	return (i);
}

int		ft_get_len(t_flags flags)
{
	int	tmp;
	int	i;

	i = 0;
	if ((flags.total < 0 && ABS(flags.total) > 0) || 1 / flags.flt < 0)
		i = 1;
	else if (flags.plus && flags.total >= 0)
		i = 1;
	else if (flags.blank && flags.total >= 0)
		i = 1;
	printf("%d", i);
	tmp = size(flags.total) - !(flags.t_dot > 0 || (flags.total != 0) || !flags.dot);
	printf(" %d",tmp);
	flags.t_dot = flags.t_dot - tmp - i;
	if (flags.t_dot < 0)
		flags.t_dot = 0;
	printf(" %d|",flags.t_dot);
	return (flags.t_dot + i + tmp);
}
