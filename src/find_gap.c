/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_gap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:53:55 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/02 19:12:49 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

Elf64_Phdr		*find_gap(t_file *file, t_elf64 *elf64)
{
	int				i;
	Elf64_Phdr		*text;

	i = -1;
	text = NULL;
	(void)file;
	while (++i < elf64->ehdr->e_phnum)
	{
		if (elf64->phdr->p_type == PT_LOAD && elf64->phdr->p_flags & 0x011)
		{
			printf("+ Found .text segment (#%d)\n", i);
			text = elf64->phdr;
		}
		elf64->phdr = (Elf64_Phdr *)((char *)elf64->phdr + elf64->ehdr->e_phentsize);
	}
	return (text);
}