/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:53:55 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/06 14:16:10 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <woody.h>

Elf64_Shdr		*find_section(void *data, char *name)
{
	int			i;
	Elf64_Ehdr	*ehdr;
	Elf64_Shdr	*shdr;
	Elf64_Shdr	*sh_strtab;
	const char	*sh_strtab_p;

	i = -1;
	ehdr = (Elf64_Ehdr *)data;
	shdr = (Elf64_Shdr *)(data + ehdr->e_shoff);
	sh_strtab = &shdr[ehdr->e_shstrndx];
	sh_strtab_p = data + sh_strtab->sh_offset;
	while (++i < ehdr->e_shnum)
	{
		if (!strcmp(sh_strtab_p + shdr[i].sh_name, name))
			return (&shdr[i]);
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
		{
			return (i);
		}
	}
	return (-1);
}

int				find_mem_substitution(void *ptr, int len, long pat, unsigned long val)
{
	unsigned char	*p;
	long			v;
	int				i;
	int				r;

	p = (unsigned char *)ptr;
	i = -1;
	while (++i < len)
	{
		v = *((long *)(p + i));
		r = v ^ pat;
		if (r == 0)
		{
			printf("%lx\n", pat);
			*((long *)(p + i)) = val;
			return (0);
		}
	}
	return (1);
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
	elf64->phdr[i].p_flags |= (PF_X | PF_W);
	woody->gap = gap;
	woody->text_end = text_end;
	return (&elf64->phdr[i]);
}
