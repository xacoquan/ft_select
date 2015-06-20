/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:38:10 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:01 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned int	i;
	char			*s2;
	unsigned char	c2;

	s2 = s;
	c2 = c;
	i = 0;
	while (i < len)
	{
		s2[i] = c2;
		i++;
	}
	return (s);
}
