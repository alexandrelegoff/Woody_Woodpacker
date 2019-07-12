/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:08:31 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/06 14:58:13 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

static int		launch_process(t_elf64 *elf64, t_file *file, t_woody *woody)
{
	if ((woody->text_segment = find_gap(file, elf64, woody)) == NULL)
		return (ret_error(NO_SPACE));
	printf("text segment size = %lx\n", woody->text_segment->p_filesz);
	woody->text_segment->p_filesz += file->size_loader;
	woody->text_segment->p_memsz += file->size_loader;
	if ((woody->text_section_file = find_section(file->ptr_file, ".text")) == NULL)
		return (ret_error(NO_TEXT));
	if ((woody->text_section_loader = find_section(file->ptr_loader, ".text")) == NULL)
		return (ret_error(NO_TEXT));
	if (woody->gap < (int)woody->text_section_loader->sh_size)
		return (ret_error(NO_SPACE));
	memmove(woody->ptr + woody->text_end,
	file->ptr_loader + woody->text_section_loader->sh_offset, woody->text_section_loader->sh_size);
	woody->text_section_file->sh_flags |= (SHF_WRITE | SHF_ALLOC);
	elf64->ehdr->e_entry = (Elf64_Addr)woody->text_segment->p_vaddr +
	woody->text_end;
	encrypt_text_helper(woody);
	decrypt_text_helper(woody, elf64);
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
	woody.ptr = malloc(sizeof(char) * (file.size_file + file.size_loader));
	memcpy(woody.ptr, file.ptr_file, file.size_file);
	elf64 = init_elf64(&woody);
	if ((verify_info(elf64.ehdr)) == EXIT_FAILURE || ((woody.key = generate_key()) == EXIT_FAILURE))
		return (EXIT_FAILURE);
	if ((status = launch_process(&elf64, &file, &woody)) == EXIT_SUCCESS)
		write_file(&file, &elf64, &woody);
	munmap(file.ptr_file, file.size_file);
	munmap(file.ptr_loader, file.size_loader);
	return (status);
}
