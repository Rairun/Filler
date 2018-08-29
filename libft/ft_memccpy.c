/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:05:53 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/23 10:12:26 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t			i;
	char			*dst1;
	const char		*src1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	while (i < n)
	{
		dst1[0] = src1[0];
		if ((unsigned char)src1[0] == c1)
			return ((void *)(++dst1));
		i++;
		src1++;
		dst1++;
	}
	return (NULL);
}
