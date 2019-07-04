/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:08:31 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 20:32:51 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

static char g_mov[] = {
	0xb8, 0x01, 0x00, 0x00, 0x00, 0xbf, 0x01, 0x00,
	0x00, 0x00, 0x48, 0x8d, 0x35, 0x0f, 0x00, 0x00,
	0x00, 0xba, 0x10, 0x00, 0x00, 0x00, 0x0f, 0x05,
	0xb8, 0x11, 0x11, 0x11, 0x11, 0xff, 0xe0
};

static int		launch_process(t_elf64 *elf64, t_file *file, t_woody *woody)
{
	if ((woody->text_segment = find_gap(file, elf64, woody)) == NULL)
		return (ret_error(NO_SPACE));
	if ((woody->text_section = find_section(elf64, ".text")) == NULL)
		return (ret_error(NO_TEXT));
	if (woody->gap < 31)
		return (ret_error(NO_SPACE));
	memmove(file->ptr_file + woody->text_end, g_mov, 31);
	elf64->ehdr->e_entry = (Elf64_Addr)woody->text_segment->p_vaddr +
	woody->text_end;
	find_mem_substitution(file->ptr_file + woody->text_end, 31, 0x11111111, elf64->entry_p);
	return (EXIT_SUCCESS);
}

int				woody_woodpacker(char *filename)
{
	t_file		file;
	t_elf64		elf64;
	t_woody		woody;
	int			status;

	if (((load_file(filename, &file.ptr_file, &file.size_file)) == EXIT_FAILURE)
	|| (load_file(LOAD, &file.ptr_loader, &file.size_loader)) == EXIT_FAILURE)
		exit(1);
	elf64 = init_elf64(&file);
	if ((verify_info(elf64.ehdr)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ((status = launch_process(&elf64, &file, &woody)) == EXIT_SUCCESS)
		write_file(&file, &elf64);
	munmap(file.ptr_file, file.size_file);
	munmap(file.ptr_loader, file.size_loader);
	return (status);
}
