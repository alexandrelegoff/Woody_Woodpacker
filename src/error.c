/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:38:53 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/30 20:45:49 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			ret_error(char *message)
{
	dprintf(2, "woody_woodpacker: error: %s\n", message);
	return (EXIT_FAILURE);
}