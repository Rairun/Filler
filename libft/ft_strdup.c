/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:44:12 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/27 17:32:28 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if ((str1 = (char *)malloc(sizeof(*str1) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
