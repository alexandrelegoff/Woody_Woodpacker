/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:08:31 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 16:28:41 by ale-goff         ###   ########.fr       */
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
	if ((load_file(LOAD, &file.ptr_loader, &file.size_loader)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	elf64 = init_elf64(&file);
	if ((verify_info(elf64.ehdr)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((woody.data_section = find_section(&elf64, ".data")) == NULL)
		return (ret_error(NO_DATA));
	if ((woody.text_segment = find_gap(&file, &elf64, &woody)) == NULL)
		return (EXIT_FAILURE);
	if ((woody.text_section = find_section(&elf64, ".text")) == NULL)
		return (ret_error(NO_TEXT));
	memmove(file.ptr_file + woody.text_end, file.ptr_file + woody.text_section->sh_offset, woody.text_section->sh_size);
	printf("+ Payload .text section found at %llx (%llx bytes)\n", woody.text_section->sh_offset, woody.text_section->sh_size);
	printf("text_end = 0x%x\n", woody.text_end);
	printf("0x%x\n", woody.gap);
	write_file(&file, &elf64);
	return (EXIT_SUCCESS);
}
