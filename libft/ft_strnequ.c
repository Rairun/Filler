/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:03:28 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/28 10:31:52 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2 && n)
	{
		i = 0;
		while (s1[i] && s2[i] && (i < n))
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s1[i] != s2[i] && (i < n))
			return (0);
	}
	return (1);
}
