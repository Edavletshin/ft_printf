/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:56:29 by galiza            #+#    #+#             */
/*   Updated: 2019/06/09 22:13:06 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	if_dot(t_flags *flags, int curr_chr, int i, const char *fmt)
{
	(*flags).t_dot = ft_atoi(fmt + curr_chr + i + 1);
	if ((*flags).t_dot <= 0)
		(*flags).t_dot = -1;
	(*flags).dot = 1;
}

static int	stan_param(t_flags *flags)
{
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
	return (0);
}

static void	if_other(t_flags *flags, int curr_chr, const char *fmt)
{
	int		q;

	q = 0;
	while (ft_strchr("#-+*.hl 0123456789", fmt[curr_chr + q]))
	{
		if (fmt[curr_chr + q] == '-')
			(*flags).minus = 1;
		if (fmt[curr_chr + q] == '.')
			if_dot(flags, curr_chr, q, fmt);
		if (fmt[curr_chr + q] == '#')
			(*flags).h_tag = 1;
		if (fmt[curr_chr + q] == ' ')
			(*flags).blank = 1;
		if (fmt[curr_chr + q] == '+')
			(*flags).plus = 1;
		q++;
	}
}

void		ft_get_keys(const char *fmt, int curr_chr, t_flags *flags)
{
	int		i;

	i = stan_param(flags);
	if_other(flags, curr_chr, fmt);
	while (ft_strchr("#-+*.hl 0123456789", fmt[curr_chr + i]))
	{
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
