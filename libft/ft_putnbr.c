/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:38:27 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:06 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if ((n / 10) == 0)
	{
		c = n + '0';
		write (1, &c, 1);
		return ;
	}
	ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}
