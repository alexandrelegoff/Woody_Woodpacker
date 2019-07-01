/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:29:12 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/30 20:44:48 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			load_file(char *filename, t_file *file)
{
	int				fd;
	struct stat		statbuf;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (ret_error(OPEN));
	if ((stat(filename, &statbuf)) == -1)
		return (ret_error(STAT));
	file->size = statbuf.st_size;
	if ((file->ptr = mmap(0, file->size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ret_error(MMAP));
	return (EXIT_SUCCESS);
}