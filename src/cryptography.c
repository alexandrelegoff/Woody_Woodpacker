#include <woody.h>

void			encrypt_text_helper(t_woody *woody)
{
	encrypt_text_section(woody->ptr + woody->text_section_file->sh_offset,
	woody->text_section_file->sh_size, woody->key);
}
