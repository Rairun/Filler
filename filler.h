/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 09:46:48 by psaprono          #+#    #+#             */
/*   Updated: 2018/08/15 09:47:09 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define AREA 900
# define WID 1000
# define HGT 1000
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

typedef int		t_idot2 __attribute__((vector_size(sizeof(int)*2)));


typedef struct	s_fill
{
	int			fd;
	char		me;
	char		en;
	t_idot2		msize;
	t_idot2		psize;
	t_idot2		bdot;
	double		blen;
	int			set;
	char		*map;
	char		*piece;
}				t_fill;

typedef	struct	s_map
{
	char			*map;
	struct s_map	*prev;
	struct s_map	*next;
}				t_map;

typedef	struct	s_vis
{
	void		*mlx;
	void		*wnd;
	void		*imp;
	char		*ims;
	int			fd;
	char		*p1;
	char		*p2;
	t_idot2		msize;
	t_map		*map;
	int			set;
	int			gap;
}				t_vis;

void			algo(t_fill *fil);

#endif
