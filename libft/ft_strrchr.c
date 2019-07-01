/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 08:54:47 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/13 09:12:17 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	c = (char)c;
	len = 0;
	while (s[len])
		len++;
	while (s[len] != c && len != 0)
		len--;
	if (s[len] == (char)c)
		return ((char*)&s[len]);
	return (0);
}
