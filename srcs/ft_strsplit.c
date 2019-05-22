/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:59:12 by galiza            #+#    #+#             */
/*   Updated: 2019/04/10 21:00:17 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char *str, char c)
{
	int		i1;
	int		total;

	total = 0;
	i1 = 0;
	while (str[i1])
	{
		while ((int)str[i1] == c)
			i1++;
		while (str[i1] && ((int)str[i1] != c))
			i1++;
		if (str[i1])
			total++;
	}
	return (total);
}

static int		check_len(char *str, char c)
{
	int		i;
	int		i1;

	i1 = 0;
	i = 0;
	while (str[i] && (int)str[i] == c)
		i++;
	while (str[i + i1] && (int)str != c)
		i1++;
	return (i1);
}

static void		set_null(int *i, int *q, int *i2)
{
	*i = 0;
	*q = 0;
	*i2 = 0;
}

char			**ft_strsplit(char const *str, char c)
{
	char	**words;
	int		i;
	int		q;
	int		i2;

	set_null(&i, &q, &i2);
	if (!str)
		return (0);
	if (!(words = (char**)malloc(sizeof(words) * (check((char *)str, c) + 2))))
		return (0);
	while (str[q])
	{
		while (str[q] == c)
			q++;
		if (!(str[q]))
			break ;
		words[i] = (char*)malloc(sizeof(**words)
				* check_len((char *)str + q, c));
		while (str[q] && str[q] != c)
			words[i][i2++] = str[q++];
		words[i++][i2] = '\0';
		i2 = 0;
	}
	words[i] = 0;
	return (words);
}
