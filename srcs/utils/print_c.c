/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:32:48 by galiza            #+#    #+#             */
/*   Updated: 2019/05/22 17:25:45 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_c(const char *fmt, va_list ap, int len)
{
	int	width;
	int	c;

	c = va_arg(ap, int);
	width = ft_atoi(fmt + len);
	if (width < 0)
	{
		ft_putchar(c);
		ft_print_spaces(fmt, len);
	}
	else
	{
		ft_print_spaces(fmt, len);
		ft_putchar(c);
	}
	return (ft_printf_aux(fmt, ap, 0, len));
}
