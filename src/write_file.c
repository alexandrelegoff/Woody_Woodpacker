/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:31:38 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/02 16:54:20 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			write_file(t_file *file, t_elf64 *elf64)
{
	int		fd;
	char	*content;

	(void)file;
	if ((fd = open(FILE, O_RDWR | O_TRUNC | O_CREAT, 0755)) == -1)
		return (ret_error(OPEN));
	content = (void *)elf64->ehdr;
	write(fd, content, SIZE_HEADER);
	close(fd);
	return (EXIT_SUCCESS);
}