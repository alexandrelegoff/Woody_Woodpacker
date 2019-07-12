/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:29:12 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 13:55:40 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			load_file(char *filename, void **ptr, off_t *size)
{
	int				fd;
	struct stat		statbuf;

	if ((fd = open(filename, O_RDWR)) == -1)
		return (ret_error(OPEN));
	if ((fstat(fd, &statbuf)) == -1)
		return (ret_error(STAT));
	*size = statbuf.st_size;
	if ((*ptr = mmap(0, *size,
	PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ret_error(MMAP));
	close(fd);
	return (EXIT_SUCCESS);
}
