#include <woody.h>

void			encrypt_text_helper(t_woody *woody)
{
	encrypt_text_section(woody->ptr + woody->text_section_file->sh_offset,
	woody->text_section_file->sh_size, woody->key);
}

void			decrypt_text_helper(t_woody *woody, t_elf64 *elf64)
{
	printf("size = %lx\n", woody->text_section_file->sh_size);
	if (find_mem_substitution(woody->ptr + woody->text_end, woody->text_section_loader->sh_size, 0x1111111111111111, elf64->entry_p))
		printf("ENTRY NOT FOUND\n");
	if (find_mem_substitution(woody->ptr + woody->text_end, woody->text_section_loader->sh_size, 0x2222222222222222, woody->key))
		printf("KEY NOT FOUND\n");
	if (find_mem_substitution(woody->ptr + woody->text_end, woody->text_section_loader->sh_size, 0x3333333333333333, woody->text_section_file->sh_size))
		printf("SIZE NOT FOUND\n");

}
