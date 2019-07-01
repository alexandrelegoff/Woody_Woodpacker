/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:35:11 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/13 23:28:26 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr;
	char		*ptr2;

	ptr = (char*)src;
	ptr2 = (char*)dst;
	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		ptr2[i] = ptr[i];
		i++;
	}
	return (dst);
}
