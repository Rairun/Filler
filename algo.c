/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:18:17 by psaprono          #+#    #+#             */
/*   Updated: 2018/08/23 10:18:19 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_best(t_fill *fil, t_idot2 it, int x, int y)
{
	int		i1;
	int		j1;
	double	len;

	len = 0;
	i1 = -1;
	while (++i1 < fil->psize[0])
	{
		j1 = -1;
		while (++j1 < fil->psize[1])
		{
			if (fil->piece[i1 * fil->psize[1] + j1] == '*')
				len += sqrt(((x + j1) - it[1]) *\
				((x + j1) - it[1]) + ((y + i1) - it[0]) * ((y + i1) - it[0]));
		}
	}
	if (fil->blen == -1 || len < fil->blen)
	{
		fil->blen = len;
		fil->bdot = (t_idot2){y, x};
	}
}

static void	get_best(t_fill *fil, int y, int x)
{
	t_idot2	it;

	it[0] = -1;
	while (++it[0] < fil->msize[0])
	{
		it[1] = -1;
		while (++it[1] < fil->msize[1])
		{
			if (fil->map[it[0] * fil->msize[1] + it[1]] == fil->en)
				check_best(fil, it, x, y);
		}
	}
}

static bool	try_set(t_fill *fil, int y, int x)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < fil->psize[0])
	{
		j = -1;
		while (++j < fil->psize[1])
		{
			if (fil->piece[i * fil->psize[1] + j] == '*')
			{
				if (y + i >= fil->msize[0] || y + i < 0 || x + j < 0 ||\
					x + j >= fil->msize[1] || fil->map[(y + i) * fil->msize[1]\
					+ (x + j)] == fil->en)
					return (0);
				if (fil->map[(y + i) * fil->msize[1] + (x + j)] == fil->me)
					if (++count > 1)
						return (0);
			}
		}
	}
	return (count == 1 ? 1 : 0);
}

static void	print_dot(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void		algo(t_fill *fil)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	i = -fil->psize[0];
	while (++i < fil->msize[0])
	{
		j = -fil->psize[1];
		while (++j < fil->msize[1])
		{
			if (try_set(fil, i, j))
				get_best(fil, i, j);
		}
	}
	if (fil->blen != -1)
		print_dot(fil->bdot[0], fil->bdot[1]);
	else
		print_dot(0, 0);
}
