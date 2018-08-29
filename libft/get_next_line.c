/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:17:22 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/07 11:24:07 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_new_size_alloc(char **s)
{
	char *tmp;

	if ((tmp = ft_strnew(ft_strlen(*s) + BUFF_SIZE)) != NULL)
		ft_memmove(tmp, *s, ft_strlen(*s));
	else
		return (NULL);
	free(*s);
	*s = NULL;
	return (tmp);
}

static int		ft_end_line_find(char *s, char c, int n)
{
	int k;

	k = 1;
	while (*s && n > 0)
	{
		if (*s == c)
			return (k);
		k++;
		s++;
		n--;
	}
	return (0);
}

static void		ft_after(char **line, char **str, size_t n)
{
	int k;

	k = 0;
	ft_bzero(*line, ft_strlen(*line));
	if ((k = ft_end_line_find(*str, '\n', n)) > 0)
	{
		ft_strncat(*line, *str, k);
		line[0][ft_strlen(*line) - 1] = '\0';
		*str = ft_memchr(*str, '\n', n) + 1;
	}
	else
	{
		ft_strncat(*line, *str, n);
		*str = NULL;
	}
	*line = ft_new_size_alloc(line);
}

static int		ft_read(int fd, char **line, char **str)
{
	int			i;
	int			k;
	static char	tmp[BUFF_SIZE + 1];

	ft_bzero(tmp, BUFF_SIZE + 1);
	while ((i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if ((k = ft_end_line_find(tmp, '\n', BUFF_SIZE)) > 0)
		{
			ft_strncat(*line, tmp, k);
			line[0][ft_strlen(*line) - 1] = '\0';
			*str = ft_memchr(tmp, '\n', BUFF_SIZE) + 1;
			return (1);
		}
		ft_strncat(*line, tmp, BUFF_SIZE);
		ft_bzero(tmp, ft_strlen(tmp));
		*line = ft_new_size_alloc(line);
	}
	if (i <= 0 && ft_strlen(*line) != 0)
		return (1);
	if (i == -1)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *str[FD_AMOUNT];
	int			er;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (str[fd] == NULL)
	{
		if ((er = ft_read(fd, line, &str[fd])) == 0)
			return (0);
		if (er == -1)
			return (-1);
		return (1);
	}
	ft_after(line, &str[fd], BUFF_SIZE);
	if (str[fd] == NULL)
	{
		if ((ft_read(fd, line, &str[fd])) == 0)
			return (0);
		return (1);
	}
	return (1);
}
