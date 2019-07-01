/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:35:56 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/12 21:21:36 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	while (haystack[i])
	{
		while (needle[pos] == haystack[i + pos])
		{
			if (pos == j - 1)
				return ((char*)haystack + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
