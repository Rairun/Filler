/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:49:57 by psaprono          #+#    #+#             */
/*   Updated: 2018/03/27 19:59:39 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(8, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		c = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = n + 48;
		write(fd, &c, 1);
	}
}
