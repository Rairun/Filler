/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:36:23 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/28 10:35:18 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*str;
	int		i;

	str = NULL;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if ((str = (char *)malloc(sizeof(str) * (len1 + len2 + 1))) == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		while (s2[i - len1])
		{
			str[i] = s2[i - len1];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
