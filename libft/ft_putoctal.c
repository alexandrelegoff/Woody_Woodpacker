/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:22:03 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/03 21:56:56 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putoctal(unsigned int n)
{
	int len;

	len = 0;
	if (n >= 8)
		len += ft_putoctal(n / 8);
	len += ft_putchar(48 + (n % 8));
	return (len);
}
