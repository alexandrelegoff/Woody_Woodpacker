/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:24:54 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 19:49:17 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			verify_info(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0)
		return (ret_error(MAGIC));
	else if (header->e_ident[EI_MAG1] != ELFMAG1)
		return (ret_error(MAGIC));
	else if (header->e_ident[EI_MAG2] != ELFMAG2)
		return (ret_error(MAGIC));
	else if (header->e_ident[EI_MAG3] != ELFMAG3)
		return (ret_error(MAGIC));
	else if (header->e_ident[EI_CLASS] != ELFCLASS64)
		return (ret_error(ARCH));
	return (EXIT_SUCCESS);
}

t_elf64		init_elf64(t_file *file)
{
	t_elf64		elf64;

	elf64.ehdr = (Elf64_Ehdr *)file->ptr_file;
	if (verify_info(elf64.ehdr))
		exit (1);
	elf64.entry_p = elf64.ehdr->e_entry;
	elf64.shdr = (Elf64_Shdr *)(file->ptr_file + elf64.ehdr->e_shoff);
	elf64.phdr = (Elf64_Phdr *)(file->ptr_file + elf64.ehdr->e_phoff);
	elf64.strtable = (void *)(file->ptr_file + elf64.shdr[elf64.ehdr->e_shstrndx].sh_offset);
	return (elf64);
}
