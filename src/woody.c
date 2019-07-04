/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:08:31 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 19:24:01 by ale-goff         ###   ########.fr       */
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
		return (ret_error(NO_SPACE));
	if ((woody.text_section = find_section(&elf64, ".text")) == NULL)
		return (ret_error(NO_TEXT));
	if (woody.gap < 31)
		return (ret_error(NO_SPACE));
	memmove(file.ptr_file + woody.text_end, g_mov, 31);
	elf64.ehdr->e_entry = (Elf64_Addr)woody.text_segment->p_vaddr + woody.text_end;
	printf("%llu\n", elf64.ehdr->e_entry);
	write_file(&file, &elf64);
	return (EXIT_SUCCESS);
}
