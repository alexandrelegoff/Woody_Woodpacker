/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:46:01 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/13 09:46:46 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr2 = (unsigned char*)dst;
	ptr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptr2[i] = ptr[i];
		if (ptr[i] == (unsigned char)c)
			return (ptr2 + i + 1);
		i++;
	}
	return (NULL);
}
