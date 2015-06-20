/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:37:14 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:40:58 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s_1;
	const unsigned char		*s_2;
	unsigned int			i;

	i = 0;
	s_1 = (const unsigned char*)s1;
	s_2 = (const unsigned char*)s2;
	while (i < n)
	{
		if (s_1[i] != s_2[i])
			return (int)(s_1[i] - s_2[i]);
		i++;
	}
	return (0);
}
