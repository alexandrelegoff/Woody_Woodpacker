/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:29:12 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/02 21:55:40 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			load_file(char *filename, t_file *file)
{
	int				fd;
	struct stat		statbuf;
	int				is_loader;

	is_loader = ft_strcmp(filename, PAYLOAD) == 0 ? 1 : 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (ret_error(OPEN));
	if ((fstat(fd, &statbuf)) == -1)
		return (ret_error(STAT));
	if (is_loader)
		file->size_loader = statbuf.st_size;
	else
		file->size_file = statbuf.st_size;
	if (is_loader && (file->ptr_loader = mmap(0, file->size_loader,
		PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ret_error(MMAP));
	else if ((file->ptr_file = mmap(0, file->size_file,
		PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ret_error(MMAP));
	close(fd);
	return (EXIT_SUCCESS);
}
