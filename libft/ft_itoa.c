/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:59:07 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/28 10:08:06 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(int n, int *neg)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*neg = 1;
		len++;
	}
	else
		*neg = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_strdup_once(const char *s1)
{
	char	*str1;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	if ((str1 = (char*)malloc(sizeof(*str1) * (len + 1))) == NULL)
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

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	len = ft_nbrlen(n, &neg);
	if (n == -2147483648)
		return (ft_strdup_once("-2147483648"));
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	if (neg == 1)
		n = n * -1;
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
