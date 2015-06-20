/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:34:42 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:40:55 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_filltemp(char *temp, int *l, int n)
{
	char	c;

	while (n != 0)
	{
		if (n < 0)
			c = '0' - (n % 10);
		else
			c = (n % 10) + '0';
		temp[(*l)--] = c;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*newc;
	char	*temp;
	int		l;
	int		neg;

	temp = ft_strdup("00000000000");
	l = 10;
	neg = 0;
	if (n == 0)
		l--;
	else
	{
		if (n < 0)
			neg = 1;
		ft_filltemp(temp, &l, n);
		if (neg == 1)
			temp[l--] = '-';
	}
	newc = ft_strsub(temp, (l + 1), ft_strlen(&temp[l]));
	free(temp);
	return (newc);
}
