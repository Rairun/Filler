/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:44:55 by psaprono          #+#    #+#             */
/*   Updated: 2018/08/27 19:44:58 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	choice(int k)
{
	if (k == 53)
		exit(1);
	return (1);
}

static int	exit_press(void)
{
	exit(1);
	return (1);
}

void		init_binds(t_vis *vis)
{
	mlx_hook(vis->wnd, 17, 1L << 17, exit_press, vis);
	mlx_hook(vis->wnd, 2, 5, choice, vis);
}

void	put_pix_to_img(t_vis *vis, t_idot2 xy, int wid, int color)
{
	if (xy[0] >= 0 && xy[0] < wid && xy[1] >= 0 && xy[1] < wid)
		*(int *)(vis->ims + ((xy[0] + xy[1] * wid) * 4)) = color;
}

void	init_vis(t_vis *vis)
{
	int	a[3];

	a[0] = 32;
	vis->mlx = mlx_init();
	vis->wnd = mlx_new_window(vis->mlx, WID, HGT, "Filler");
	vis->imp = mlx_new_image(vis->mlx, AREA, AREA);
	vis->ims = mlx_get_data_addr(vis->imp, &a[0], &a[1], &a[2]);
	init_binds(vis);
}

int		ft_strrchr_n(const char *s, int c)
{
	char	*str;
	int		i;
	int		res;

	str = (char *)s;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			res = i;
	if (str[i] == c)
		res = i;
	return (res);
}

void	set_player(bool p, char *line, int start, t_vis *vis)
{
	int		i;

	i = start;
	while (line[i] != ']' && line[i] != '\0')
		i++;
	if (p)
		vis->p2 = ft_strsub(line, start, i - start);
	else
		vis->p1 = ft_strsub(line, start, i - start);
}

bool	get_players(t_vis *vis)
{
	char	*line;
	bool	n;

	line = NULL;
	n = 0;
	// ft_putendl_fd("1", vis->fd);
	while (n == 0 && get_next_line(0, &line) > -1)
	{
		if (ft_strncmp(line, "$$$ exec p", 9) == 0)
		{
			// ft_putendl_fd("2", vis->fd);
			if (line[10] == '1')
				set_player(0, line, ft_strrchr_n(line, '/') + 1, vis);
			else if (line[10] == '2')
				set_player(n = 1, line, ft_strrchr_n(line, '/') + 1, vis);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

bool	get_map_size(t_vis *vis)
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
			vis->msize[0] = ft_atoi(line + i);
			while (line[i] != ' ')
				i++;
			vis->msize[1] = ft_atoi(line + i + 1);
		}
		ft_strdel(&line);
	}
	return (n);
}

t_map	*new_map(char *map, t_map *prev)
{
	t_map	*new;

	if ((new = ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	new->map = map;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

void	print_map(t_vis *vis, char *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vis->msize[0])
	{
		j = -1;
		while (++j < vis->msize[1])
			ft_putchar_fd(map[i * vis->msize[1] + j], vis->fd);
		ft_putchar_fd('\n', vis->fd);
	}
	ft_putchar_fd('\n', vis->fd);
	ft_putchar_fd('\n', vis->fd);
}

void	add_new_map(t_vis *vis, char *map)
{
	t_map	*curr;

	curr = vis->map;
	if (curr != NULL)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new_map(map, curr);
	}
	else
		vis->map = new_map(map, NULL);
}

void	get_map(t_vis *vis)
{
	char	*line;
	char	*map;
	int		i;
	int		j;

	i = -1;
	line = NULL;
	vis->set = -1;
	if ((map = ft_strnew(vis->msize[0] * vis->msize[1])) == NULL)
		ft_putendl_fd("Error malloc map", vis->fd);
	while (++i < vis->msize[0] && get_next_line(0, &line) > -1)
	{
		j = 3;
		while (line[++j] != '\0')
			map[++(vis->set)] = line[j];
		ft_strdel(&line);
	}
	add_new_map(vis, map);
}

void	print_maps(t_vis *vis, t_map *map)
{
	t_map	*curr;

	curr = map;
	while (curr->next)
	{
		print_map(vis, curr->map);
		curr = curr->next;
	}
}

void	print_line(t_vis *vis, int start, int len, bool is)
{
	int	i;

	if (!is)
	{
		i = (AREA - vis->gap * vis->msize[1]);
		while (++i <= len)
			put_pix_to_img(vis, (t_idot2){i, start}, AREA, 0xFFFFFF);
	}
	else
	{
		i = (AREA - vis->gap * vis->msize[0]);
		while (++i <= len)
			put_pix_to_img(vis, (t_idot2){start, i}, AREA, 0xFFFFFF);
	}
}

void	draw_nest(t_vis *vis)
{
	int	i;
	int	j;
	int	top;

	i = (AREA - vis->gap * vis->msize[0]) / 2;
	j = vis->gap * vis->msize[1];
	top = vis->gap * vis->msize[0] + i;
	while (i <= top)
	{
		ft_putnbr_fd(i, vis->fd);
		ft_putchar_fd(' ', vis->fd);
		ft_putnbr_fd(j, vis->fd);
		ft_putchar_fd(' ', vis->fd);
		ft_putnbr_fd(top, vis->fd);
		ft_putchar_fd('\n', vis->fd);
		print_line(vis, i, j, 0);
		i += vis->gap;
	}
	// i = (AREA - vis->gap * vis->msize[1]) / 2;
	// j = vis->gap * vis->msize[0];
	// top = vis->gap * vis->msize[1];
	// while (i <= top)
	// {
	// 	ft_putnbr_fd(i, vis->fd);
	// 	ft_putchar_fd(' ', vis->fd);
	// 	ft_putnbr_fd(j, vis->fd);
	// 	ft_putchar_fd(' ', vis->fd);
	// 	ft_putnbr_fd(top, vis->fd);
	// 	ft_putchar_fd('\n', vis->fd);
	// 	print_line(vis, i, j, 1);
	// 	i += vis->gap;
	// }
}

void	visualize(t_vis *vis)
{
	int	i;
	int	j;

	init_vis(vis);
	i = -1;
	vis->gap = AREA / (vis->msize[0] > vis->msize[1] ? vis->msize[0] : vis->msize[1]);
	while (++i < AREA)
	{
		j = -1;
		while (++j < AREA)
			put_pix_to_img(vis, (t_idot2){j, i}, AREA, 0x555555);
	}
	draw_nest(vis);
	mlx_put_image_to_window(vis->mlx, vis->wnd, vis->imp, (WID - AREA) / 2, (HGT - AREA) / 2);
	mlx_loop(vis->mlx);
}

int		main(void)
{
	int		fd;
	t_vis	*vis;
	char	*line;

	fd = open("result", O_RDWR | O_APPEND | O_CREAT);
	if ((vis = ft_memalloc(sizeof(t_vis))) == NULL)
		ft_putendl_fd("Error malloc t_fill", fd);
	vis->fd = fd;
	vis->map = NULL;
	vis->p1 = NULL;
	vis->p2 = NULL;
	sleep(1);
	if (get_players(vis) && get_map_size(vis))
	{
		while (get_next_line(0, &line) > 0)
		{
			if (ft_strncmp(line, "    01234567890123456", 20) == 0)
				get_map(vis);
			// else if (ft_strncmp(line, "== O fin: ", 9) == 0)
			// 	get_fin(0, vis);
			// else if (ft_strncmp(line, "== X fin: ", 9) == 0)
			// 	get_fin(1, vis);
			ft_strdel(&line);
		}
		visualize(vis);
		// print_maps(vis, vis->map);
	}
	system("leaks -q a.out");
	return (0);
}
