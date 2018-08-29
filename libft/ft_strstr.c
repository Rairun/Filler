/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:05:36 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/28 10:09:04 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *hay;
	const char *need;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			hay = haystack;
			need = needle;
			while (*hay++ == *need++)
				if (*need == '\0')
					return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
