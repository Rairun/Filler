/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:07:31 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/23 13:29:00 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*cur;

	cur = s1;
	while (*cur != '\0')
		cur++;
	while (*s2 != '\0' && n > 0)
	{
		*cur = *s2;
		cur++;
		s2++;
		n--;
	}
	*cur = '\0';
	return (s1);
}
