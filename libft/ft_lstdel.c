/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:28:40 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/27 15:28:50 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *pointer;

	pointer = *alst;
	while (pointer && del)
	{
		del(pointer->content, pointer->content_size);
		free(pointer);
		pointer = pointer->next;
	}
	*alst = NULL;
}
