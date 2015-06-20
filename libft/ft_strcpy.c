/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 10:15:29 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:11 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		if (s2[i] == '\0')
		{
			while (s1[i] != '\0')
			{
				s1[i] = '\0';
				i++;
			}
			return (s1);
		}
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
