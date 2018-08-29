/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:40:58 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/28 10:08:54 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hay;
	const char	*need;
	size_t		l;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len--)
	{
		if (*haystack == *needle)
		{
			hay = haystack;
			need = needle;
			l = len + 1;
			while (*hay++ == *need++ && l--)
				if (*need == '\0')
					return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
