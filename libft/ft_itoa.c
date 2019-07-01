/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:05:28 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/13 20:48:34 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_digits(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < count)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_digits(n);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	new[len] = 0;
	if (n < 0)
	{
		new[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < len--)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
