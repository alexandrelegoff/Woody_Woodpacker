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

int			write_file(t_file *file, t_elf64 *elf64, t_woody *woody)
{
	int		fd;
	(void)elf64;
	if ((fd = open("woody", O_RDWR | O_TRUNC | O_CREAT, 0755)) == -1)
		return (ret_error(OPEN));
	write(fd, woody->ptr, file->size_file);
	close(fd);
	return (EXIT_SUCCESS);
}
