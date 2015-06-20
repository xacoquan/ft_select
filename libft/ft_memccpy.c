/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:34:59 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:40:56 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	char			*s_1;
	const char		*s_2;
	unsigned char	c_;

	i = 0;
	s_1 = s1;
	s_2 = s2;
	c_ = c;
	while (i < n)
	{
		s_1[i] = s_2[i];
		if (s_2[i] == c_)
			return (&s_1[i + 1]);
		i++;
	}
	return (NULL);
}
