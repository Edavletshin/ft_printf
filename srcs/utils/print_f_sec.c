/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:33:54 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/07/27 17:25:02 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*create_line(char *ftitoa, int time, char *line)
{
	char		*rest;

	ftitoa = clean_fract_one(ftitoa);
	rest = malloc(sizeof(char) * (time * 9) + 1);
	ft_bzero(rest, (time * 9) + 1);
	if (line)
		rest = ft_strcat(rest, line);
	rest = ft_strcat(rest, ftitoa);
	free(ftitoa);
	if (line)
		free(line);
	return (rest);
}

static int		check_long_str(char *line, int accur)
{
	int			q;

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

static int		putstr_frac(char *line, int accur)
{
	int			q;
	char		sym;

	q = 0;
	while (line[q] && q < accur)
	{
		sym = line[q];
		write(1, &sym, 1);
		q++;
	}
	return (q);
}

static void		rouding(char *line, int accur)
{
	int			q;
	int			flag;

	flag = 0;
	q = ft_strlen(line) - 1;
	while (q > 0)
	{
		if (line[q] == '9' || line[q] == 58)
		{
			line[q] = '0';
			line[q - 1]++;
			if (line[q - 1] == 58 && q - 1 == 0)
				line[q - 1] = '0';
			if (q == accur)
				flag = 1;
		}
		if (q == accur && !flag)
			break ;
		q--;
	}
}

int				print_fract(long double n, int len, int accur)
{
	char		*line;
	int			check;
	long int	copy;
	int			time;

	check = 1;
	time = 1;
	line = NULL;
	while (check)
	{
		copy = n;
		n -= copy;
		if (n < 0)
			n *= -1;
		n += 1.0;
		n *= 1000000000;
		line = create_line(ft_itoa(n), time, line);
		check = check_long_str(line, accur);
		time++;
	}
	rouding(line, accur);
	len += putstr_frac(line, accur);
	ft_strdel(&line);
	return (len);
}
