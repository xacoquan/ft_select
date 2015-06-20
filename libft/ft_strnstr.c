/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 10:18:43 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:22 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	int			c;

	i = 0;
	c = 0;
	if (s2[0] == '\0')
		return (char*)(s1);
	while (i < n && s1[i])
	{
		j = i;
		c = 0;
		while (s1[j] == s2[c] && j < n)
		{
			j++;
			c++;
			if (s2[c] == '\0')
				return (char*)(&s1[i]);
		}
		i++;
	}
	return (NULL);
}
