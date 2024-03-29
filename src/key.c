/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:51:24 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/06 14:59:11 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

uint64_t		generate_key(void)
{
	uint64_t	key;
	int		fd;

	if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
		return (ret_error(OPEN));
	if ((read(fd, &key, sizeof(key)) != sizeof(key)))
		return (ret_error(UNKWN));
	printf("Pseudo-Random Generated key: = 0x%lx\n", key);
	close(fd);
	return (key);
}
