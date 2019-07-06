/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:24:54 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/06 13:57:19 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			verify_info(Elf64_Ehdr *header)
{
	if (strncmp((void *)header, ELFMAG, SELFMAG))
		return (ret_error(MAGIC));
	else if (header->e_ident[EI_CLASS] != ELFCLASS64)
		return (ret_error(ARCH));
	else if (header->e_type != ET_EXEC)
		return (ret_error(EXEC));
	else if (header->e_shentsize != sizeof(Elf64_Shdr))
		return (ret_error(UNKWN));
	else if (header->e_phentsize != sizeof(Elf64_Phdr))
		return (ret_error(UNKWN));
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
