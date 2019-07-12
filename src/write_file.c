/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:31:38 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 19:28:56 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			write_file(t_file *file)
{
	int		fd;

	if ((fd = open("woody", O_RDWR | O_TRUNC | O_CREAT, 0755)) == -1)
		return (ret_error(OPEN));
	write(fd, file->ptr_file, file->size_file);
	close(fd);
	return (EXIT_SUCCESS);
}
