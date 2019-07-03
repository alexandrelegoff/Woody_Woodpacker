/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:53:55 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/03 14:08:05 by ale-goff         ###   ########.fr       */
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

Elf64_Phdr		*find_gap(t_file *file, t_elf64 *elf64)
{
	Elf64_Phdr		*text_seg;
	int				i;

	i = -1;
	(void)file;
	text_seg = NULL;
	while (++i < elf64->ehdr->e_phnum)
	{
		if (elf64->phdr[i].p_type == PT_LOAD)
		{
			if (elf64->phdr[i].p_flags & 0x011)
				printf("SALUT1\n");
			else
				printf("SALUT2\n");
			text_seg = &elf64->phdr[i];
		}
	}
	return (text_seg);
}
