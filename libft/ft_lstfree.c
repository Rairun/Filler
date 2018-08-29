/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:36:19 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/14 15:36:23 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfree(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		ft_strdel((char **)&(list->content));
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
