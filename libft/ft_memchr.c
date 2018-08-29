/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:05:40 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/23 14:07:50 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*s1;
	size_t			i;
	unsigned char	cc;

	s1 = (char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] == cc)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}
