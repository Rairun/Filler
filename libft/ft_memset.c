/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:24:18 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/26 12:59:37 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	c1;

	str = (char *)b;
	c1 = (char)c;
	i = 0;
	while (i < len)
	{
		str[i] = c1;
		i++;
	}
	return ((void *)b);
}
