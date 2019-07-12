#include <woody.h>

void			encrypt_text_helper(t_woody *woody, t_file *file)
{
	encrypt_text_section(file->ptr_file + woody->text_section_file->sh_offset,
	woody->text_section_file->sh_size, woody->key);
}

void			decrypt_text_helper(t_file *file, t_elf64 *elf64, t_woody *woody)
{
	printf("Original entry point = %lx\n", elf64->entry_p);
	if (find_mem_substitution(file->ptr_file + woody->text_end, woody->text_section_loader->sh_size, 0x1111111111111111, elf64->entry_p))
		printf("ENTRY NOT FOUND\n");
	if (find_mem_substitution(file->ptr_file + woody->text_end, woody->text_section_loader->sh_size, 0x2222222222222222, woody->key))
		printf("KEY NOT FOUND\n");
	if (find_mem_substitution(file->ptr_file + woody->text_end, woody->text_section_loader->sh_size, 0x3333333333333333, woody->text_section_file->sh_size))
		printf("SIZE NOT FOUND\n");

}
