/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 10:39:40 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/13 20:45:53 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *cpy;

	cpy = malloc(size);
	if (cpy == NULL)
		return (NULL);
	ft_memset(cpy, 0, size);
	return (cpy);
}
