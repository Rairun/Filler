/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:52:06 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/28 11:24:13 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			len++;
		}
		else
			i++;
	}
	return (len);
}

static int		ft_word_length(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char		*ft_memgive(const char *s, int len)
{
	char	*str;
	int		i;

	if ((str = (char *)malloc(sizeof(str) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;

	arr = NULL;
	if (s)
	{
		if ((arr = (char **)malloc(sizeof(arr) * (ft_count(s, c) + 1))) == NULL)
			return (NULL);
		k = 0;
		i = 0;
		while (s[i])
		{
			if (s[i] != c)
			{
				arr[k++] = ft_memgive(s + i, ft_word_length(s + i, c));
				i += ft_word_length(s + i, c);
			}
			else
				i++;
		}
		arr[k] = 0;
	}
	return (arr);
}
