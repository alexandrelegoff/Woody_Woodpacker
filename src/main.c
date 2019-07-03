/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:59:27 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/01 19:00:08 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int		main(int ac, char **av)
{
	int		ret;

	ret = 0;
	if (ac == 2)
	{
		ret = woody_woodpacker(av[1]);
	}
	else
	{
		dprintf(2, USAGE);
	}
	return (ret);
}