/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:37:45 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:00 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memdup(void const *s, size_t len)
{
	void	*ret;

	if (s == NULL || ((ret = malloc(len))) == NULL)
		return (NULL);
	ft_memcpy(ret, s, len);
	return (ret);
}
