/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:56:29 by galiza            #+#    #+#             */
/*   Updated: 2019/05/31 15:48:56 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_width(int width, t_flags flags)
{
	while (width-- > 0)
		flags.zero ? ft_putchar('0') : ft_putchar(' ');
}

int		ft_print_spaces(t_flags flags, int size_int)
{
	int		width;

	flags.t_dot -= size_int - (flags.total < 0 || flags.plus);
	if (flags.t_dot < 0)
		flags.t_dot = 0;
	width = ABS(flags.padding) - size_int - flags.t_dot;
	if (width < 0)
		width = 0;
	print_width(width, flags);
	return (width + flags.t_dot - ((!flags.total && !flags.un_tot)
				&& flags.t_dot > 0));
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

void	ft_get_keys(const char *fmt, int curr_chr, t_flags *flags)
{
	int	i;

	i = 0;
	(*flags).minus = 0;
	(*flags).dot = 0;
	(*flags).blank = 0;
	(*flags).plus = 0;
	(*flags).t_dot = 0;
	(*flags).zero = 0;
	(*flags).flags = 0;
	(*flags).h_tag = 0;
	(*flags).total = 0;
	(*flags).un_tot = 0;
	while (ft_strchr("#-+*.hl 0123456789", fmt[curr_chr + i]))
	{
		if (fmt[curr_chr + i] == '-')
			(*flags).minus = 1;
		if (fmt[curr_chr + i] == '.')
		{
			(*flags).t_dot = ft_atoi(fmt + curr_chr + i + 1);
			(*flags).dot = 1;
		}
		if (fmt[curr_chr + i] == '#')
			(*flags).h_tag = 1;
		if (fmt[curr_chr + i] == ' ')
			(*flags).blank = 1;
		if (fmt[curr_chr + i] == '+')
			(*flags).plus = 1;
		if (fmt[curr_chr + i] == 'h' && fmt[curr_chr + i + 1] == 'h')
			(*flags).flags |= HH;
		if (fmt[curr_chr + i] == 'h')
			(*flags).flags |= H;
		if (fmt[curr_chr + i] == 'l')
			(*flags).flags |= L;
		if (fmt[curr_chr + i] == 'l' && fmt[curr_chr + i + 1] == 'l')
			(*flags).flags |= LL;
		i++;
	}
	(*flags).len = i;
	ft_get_int(fmt, curr_chr, flags);
	(*flags).padding = ft_atoi(fmt + curr_chr + (*flags).l_int);
}

int		ft_print_keys(t_flags flags, int size_int)
{
	int	i;

	i = 0;
	if (flags.total < 0 && ABS(flags.total) > 0)
	{
		ft_putchar('-');
		i = 1;
	}
	else if (flags.plus && flags.total >= 0)
	{
		ft_putchar('+');
		i = 1;
	}
	else if (flags.blank && flags.total > 0 && !flags.dot)
	{
		ft_putchar(' ');
		i = 1;
	}
	flags.t_dot -= size_int - (flags.total < 0 || flags.plus) +
		(!flags.total && !flags.un_tot);
	while (flags.t_dot-- > 0)
		ft_putchar('0');
	if (i)
		return (1);
	return (0);
}

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
	ft_putchar('.');
	while (accur)
	{
		accur--;
		tmp = (int)(flags.flt * size) % 10;
		size *= 10;
		ft_putnbr(ABS(tmp));
	}
	return (0);
}
