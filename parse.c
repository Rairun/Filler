/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:53:38 by psaprono          #+#    #+#             */
/*   Updated: 2018/08/14 14:53:54 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static bool	get_player(t_fill *fil)
{
	char	*line;
	bool	n;

	line = NULL;
	n = 0;
	if (get_next_line(0, &line) > -1)
	{
		if (ft_strncmp(line, "$$$ exec p", 9) == 0)
		{
			if (line[10] == '1')
			{
				fil->me = 'O';
				fil->en = 'X';
			}
			else if (line[10] == '2')
			{
				fil->me = 'X';
				fil->en = 'O';
			}
			n = 1;
		}
	}
	ft_strdel(&line);
	return (n);
}

static bool	get_map_size(t_fill *fil)
{
	char	*line;
	bool	n;
	int		i;

	line = NULL;
	n = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau ", 8) == 0)
		{
			n = 1;
			i = 8;
			fil->msize[0] = ft_atoi(line + i);
			while (line[i] != ' ')
				i++;
			fil->msize[1] = ft_atoi(line + i + 1);
		}
		ft_strdel(&line);
	}
	if ((fil->map = ft_strnew(fil->msize[0] * fil->msize[1])) == NULL)
		ft_putendl_fd("Error malloc map", fil->fd);
	return (n);
}

static void	get_map(t_fill *fil)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	line = NULL;
	fil->set = -1;
	while (++i < fil->msize[0] && get_next_line(0, &line) > -1)
	{
		j = 3;
		while (line[++j] != '\0')
			fil->map[++(fil->set)] = line[j];
		ft_strdel(&line);
	}
	fil->blen = -1;
}

static void	get_piece(t_fill *fil, char *line)
{
	int		i;
	int		j;
	char	*line1;

	i = 0;
	fil->psize[0] = ft_atoi(line);
	while (line[i] != ' ')
		i++;
	fil->psize[1] = ft_atoi(line + i + 1);
	ft_strdel(&fil->piece);
	if ((fil->piece = ft_strnew(fil->psize[0] * fil->psize[1])) == NULL)
		ft_putendl_fd("Error malloc piece", fil->fd);
	i = -1;
	fil->set = -1;
	while (++i < fil->psize[0] && get_next_line(0, &line1) > -1)
	{
		j = -1;
		while (line1[++j] != '\0')
			fil->piece[++(fil->set)] = line1[j];
		ft_strdel(&line1);
	}
	algo(fil);
}

int			main(void)
{
	t_fill		*fil;
	char		*line;
	int			fd;

	fd = open("trace", O_RDWR | O_APPEND | O_CREAT);
	if ((fil = ft_memalloc(sizeof(t_fill))) == NULL)
		ft_putendl_fd("Error malloc t_fill", fd);
	fil->fd = fd;
	fil->piece = NULL;
	if (get_player(fil) && get_map_size(fil))
	{
		while (get_next_line(0, &line) > 0)
		{
			if (ft_strncmp(line, "    01234567890123456", 20) == 0)
				get_map(fil);
			else if (ft_strncmp(line, "Piece ", 6) == 0)
				get_piece(fil, line + 6);
			ft_strdel(&line);
		}
	}
	return (0);
}
