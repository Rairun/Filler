/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:12:28 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/27 17:05:02 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*find;
	char	*str;
	char	cc;
	int		i;

	find = NULL;
	str = (char *)s;
	cc = (char)c;
	i = 0;
	while (*str)
	{
		if (*str == cc)
			find = str;
		str++;
	}
	if (*str == cc)
		find = str;
	return (find);
}
