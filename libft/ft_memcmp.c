/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:56:48 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/13 23:28:33 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr;
	const unsigned char	*ptr2;

	if (s1 == s2 || n == 0)
		return (0);
	ptr = (const unsigned char*)s1;
	ptr2 = (const unsigned char*)s2;
	while (n--)
	{
		if (*ptr != *ptr2)
			return (*ptr - *ptr2);
		if (n)
		{
			ptr++;
			ptr2++;
		}
	}
	return (0);
}
