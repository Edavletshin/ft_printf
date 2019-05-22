/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:47:33 by galiza            #+#    #+#             */
/*   Updated: 2019/05/22 19:42:32 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_width(int width, int flag)
{
	while (width--)
		flag ? ft_putchar('0') : ft_putchar(' ');
}

int		ft_print_spaces(const char *fmt, int len)
{
	int	minus;
	int	i;
	int	flag;
	int	width;

	minus = 0;
	flag = 0;
	i = 0;
	while ((fmt[len + i] < 'a' || fmt[len + i] > 'z')
			&& (fmt[len + i] < 'A' || fmt[len + i] > 'Z'))
	{
		if (fmt[len + i] == '-')
			minus = 1;
		i++;
	}
	while ((fmt[len + i] < '0' || fmt[len + i] > '9') && i > len)
		i--;
	while (fmt[len + i] >= '0' || fmt[len + i] <= '9')
		i--;
	i++;
	if (fmt[len + i] == '0' && !minus)
		flag = 1;
	width = ft_atoi(fmt + len);
	print_width(--width, flag);
	return (width);
}
