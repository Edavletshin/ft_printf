/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:47:39 by galiza            #+#    #+#             */
/*   Updated: 2019/04/12 17:20:51 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*temp;

	list = *alst;
	while (list->next)
	{
		temp = list->next;
		ft_lstdelone(&list, del);
		list = temp;
	}
	ft_lstdelone(&list, del);
	*alst = list;
}
