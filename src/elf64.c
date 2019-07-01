/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:24:54 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/30 21:45:31 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

int			verify_info(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0)
		return (ret_error(MAGIC));
	if (header->e_ident[EI_MAG1] != ELFMAG1)
		return (ret_error(MAGIC));
	if (header->e_ident[EI_MAG2] != ELFMAG2)
		return (ret_error(MAGIC));
	if (header->e_ident[EI_MAG3] != ELFMAG3)
		return (ret_error(MAGIC));
	if (header->e_ident[EI_CLASS] != ELFCLASS64)
		return (ret_error(ARCH));
	return (EXIT_SUCCESS);
}

t_elf64		init_elf64(t_file *file)
{
	t_elf64		elf64;

	elf64.header = (Elf64_Ehdr *)file->ptr;
	elf64.section_header = (Elf64_Shdr *)file->ptr + elf64.header->e_shoff;
	elf64.program_header = (Elf64_Phdr *)file->ptr + elf64.header->e_phoff;
	return elf64;
}