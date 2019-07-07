/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:07:29 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/06 15:00:08 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_H
# define WOODY_H

# include <libft.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <elf.h>

# define LOAD "asm/decrypt"
# define FILEN "woody"
# define USAGE "usage: ./woody_woodpacker <filename>\n"
# define OPEN "Couldn't open the file"
# define STAT "Stat failed"
# define MMAP "Mmap failed"
# define MAGIC "Invalid file: The file is not a valid ELF file."
# define ARCH "Invalid file: The file is not in 64 bits"
# define UNKWN "Unknown error"
# define EXEC "The file is not a valid executable file"
# define NO_DATA "Couldn't find data section"
# define NO_TEXT "Couldn't find text section"
# define NO_SPACE "Not enough space in the executable"

# define SIZE_HEADER sizeof(Elf64_Ehdr)

typedef struct		s_file
{
	off_t			size_file;
	off_t			size_loader;
	void			*ptr_file;
	void			*ptr_loader;
}					t_file;

typedef struct		s_elf64
{
	Elf64_Ehdr		*ehdr;
	Elf64_Shdr		*shdr;
	Elf64_Phdr		*phdr;
	Elf64_Addr		entry_p;
}					t_elf64;

typedef struct		s_woody
{
	int				gap;
	int				text_end;
	uint64_t		key;
	void			*ptr;
	Elf64_Phdr		*text_segment;
	Elf64_Shdr		*text_section_loader;
	Elf64_Shdr		*text_section_file;
	Elf64_Shdr		*data_section;
}					t_woody;

int					woody_woodpacker(char *file);
int					load_file(char *filename, void **ptr, off_t *size);
t_elf64				init_elf64(t_woody *woody);
int					verify_info(Elf64_Ehdr *header);
uint64_t			generate_key(void);
int					ret_error(char *message);
int					write_file(t_file *file, t_elf64 *elf64, t_woody *woody);
Elf64_Phdr			*find_gap(t_file *file, t_elf64 *elf64, t_woody *woody);
Elf64_Shdr			*find_section(void *data, char *name);
int					find_mem_substitution(void *ptr, int len, long pat, unsigned long val);
void				encrypt_text_section(char *ptr, Elf64_Addr size, uint64_t key);
void				encrypt_text_helper(t_woody *woody);
void				decrypt_text_helper(t_woody *woody, t_elf64 *elf64);

#endif
