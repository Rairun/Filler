/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:05:10 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/21 16:51:05 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **lst, void *ptr)
{
	t_list	*curr;

	if (*lst == NULL)
		*lst = ptr;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = ptr;
	}
}
