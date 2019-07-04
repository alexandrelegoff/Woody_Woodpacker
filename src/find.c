/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:53:55 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 19:52:49 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

Elf64_Shdr		*find_section(t_elf64 *elf64, char *name)
{
	int			i;

	i = -1;
	while (++i < elf64->ehdr->e_shnum)
	{
		if (!ft_strcmp(&elf64->strtable[elf64->shdr[i].sh_name], name))
			return (&elf64->shdr[i]);
	}
	return (NULL);
}

static int		find_index_segment_text(t_elf64 *elf64)
{
	int			i;

	i = -1;
	while (++i < elf64->ehdr->e_phnum)
	{
		if (elf64->phdr[i].p_type == PT_LOAD &&
		elf64->phdr[i].p_flags & (PF_X))
			return (i);
	}
	return (-1);
}

Elf64_Phdr		*find_gap(t_file *file, t_elf64 *elf64, t_woody *woody)
{
	int				i;
	int				text_end;
	int				gap;

	if ((i = find_index_segment_text(elf64)) == -1)
		return (NULL);
	gap = file->size_file;
	text_end = elf64->phdr[i].p_offset + elf64->phdr[i].p_filesz;
	if (((int)elf64->phdr[i + 1].p_offset - text_end) < gap)
		gap = elf64->phdr[i + 1].p_offset - text_end;
	else
		return (NULL);
	elf64->phdr[i + 1].p_flags |= PF_X;
	woody->gap = gap;
	woody->text_end = text_end;
	return (&elf64->phdr[i]);
}
