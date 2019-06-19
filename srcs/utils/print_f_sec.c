/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:33:54 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/06/09 20:41:46 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_line(char *ftitoa, int time, char *line)
{
	char	*res;

	res = malloc(sizeof(char) * (time * 9) + 1);
	if (line)
		res = ft_strcat(res, line);
	res = ft_strcat(res, ftitoa);
	free(ftitoa);
	if (line)
		free(line);
	return (res);
}

static int	check_long_str(char *line, int accur)
{
	int		q;

	q = ft_strlen(line) - 1;
	if (q > accur)
	{
		while (q > accur)
		{
			if (line[q] < '4')
				return (0);
			q--;
		}
	}
	return (1);
}

static int	putstr_frac(char *line, int accur)
{
	int		q;
	char	sym;

	q = 0;
	while (line[q] && q < accur)
	{
		sym = line[q];
		write(1, &sym, 1);
		q++;
	}
	return (q);
}

static void	rouding(char *line, int accur)
{
	int		q;
	int		flag;

	flag = 0;
	q = ft_strlen(line) - 1;
	while (q > 0)
	{
		if (line[q] == '9' || line[q] == 58)
		{
			line[q] = '0';
			line[q - 1]++;
			if (q == accur)
				flag = 1;
		}
		if (q == accur && !flag)
			break ;
		q--;
	}
}

int			print_fract(long double n, int len, int accur)
{
	char	*line;
	int		check;
	int		copy;
	int		time;

	check = 1;
	time = 1;
	line = NULL;
	while (check)
	{
		copy = n;
		n -= copy;
		n *= 1000000000;
		line = create_line(ft_itoa(n), time, line);
		check = check_long_str(line, accur);
		time++;
	}
	rouding(line, accur);
	len += putstr_frac(line, accur);
	return (len);
}
