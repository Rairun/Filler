/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:51:42 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/21 16:52:10 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, int len)
{
	t_list	*curr;
	int		i;

	curr = lst;
	i = 0;
	while (curr)
	{
		if (i == len)
		{
			i = 0;
			ft_putchar('\n');
		}
		ft_putstr((char *)(curr->content));
		ft_putchar('\t');
		curr = curr->next;
		i++;
	}
	ft_putchar('\n');
}
