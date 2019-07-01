/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:07:29 by ale-goff          #+#    #+#             */
/*   Updated: 2019/06/30 21:44:59 by ale-goff         ###   ########.fr       */
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

# define USAGE "./woody_woodpacker [filename]\n"
# define OPEN "Couldn't open the file"
# define STAT "Stat failed"
# define MMAP "Mmap failed"
# define MAGIC "Invalid file: The file is not a valid ELF file."
# define ARCH "Invalid file: The file is not in 64 bits"

typedef struct		s_file
{
	void			*ptr;
	off_t			size;
}					t_file;

typedef struct		s_elf64
{
	Elf64_Ehdr		*header;
	Elf64_Shdr		*section_header;
	Elf64_Phdr		*program_header;
}					t_elf64;

int					woody_woodpacker(char *file);
int					load_file(char *filename, t_file *file);
t_elf64				init_elf64(t_file *file);
int					verify_info(Elf64_Ehdr *header);

int					ret_error(char *message);

#endif