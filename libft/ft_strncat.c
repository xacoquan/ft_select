/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 10:17:50 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:17 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned int	t;

	i = 0;
	t = 0;
	while (s1[i] != '\0')
		i++;
	while (t < n && s2[t])
		s1[i++] = s2[t++];
	s1[i] = '\0';
	return (s1);
}
