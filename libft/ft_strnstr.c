/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:22:33 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/13 11:59:52 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int pos;

	pos = 0;
	j = 0;
	i = 0;
	while (needle[j])
		j++;
	if (j == 0)
		return ((char*)haystack);
	while (haystack[i] && len)
	{
		while (needle[pos] == haystack[i + pos] && len - pos)
		{
			if (pos == j - 1)
				return ((char*)haystack + i);
			pos++;
		}
		pos = 0;
		i++;
		len--;
	}
	return (0);
}
