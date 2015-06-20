/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:33:32 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:41:38 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		neg;
	int		i;

	i = -1;
	neg = 1;
	nb = 0;
	if (!str)
		return (0);
	while (str[++i] != '\0' && !ft_isdigit(str[i])
			&& str[i] != 43 && str[i] != 45)
		if (str[i] < 9 || (str[i] > 13
			&& str[i] != 32 && str[i] != 43 && str[i] != 45))
			return (0);
	if (str[i] == '-')
	{
		i++;
		neg = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nb = nb * 10 + str[i++] - '0';
	return (nb * neg);
}
