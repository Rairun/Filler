/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:11:26 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/28 10:26:29 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		len;

	str = NULL;
	if (s && f)
	{
		len = ft_strlen(s);
		if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
