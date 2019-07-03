/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:08:31 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 13:56:57 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int				woody_woodpacker(char *filename)
{
	t_file		file;
	t_elf64		elf64;
	t_woody		woody;

	if ((load_file(filename, &file.ptr_file, &file.size_file)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((load_file(PAYLOAD, &file.ptr_loader, &file.size_file)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	elf64 = init_elf64(&file);
	if ((verify_info(elf64.ehdr)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((woody.text_segment = find_gap(&file, &elf64)) == NULL)
		return (EXIT_FAILURE);
	woody.text_section = find_section(&elf64, ".text");
	return (EXIT_SUCCESS);
}
