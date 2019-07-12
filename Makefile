WOODY	=		woody_woodpacker
DECRYPT	=		decrypt

CC 		=		gcc
CFLAGS	= 		-g3 -Wall -Werror -Wextra
INC		=		-I ./inc -I libft/

ASM	=		nasm
ASMFLAGS	=	-f elf64

SRC_DIR =		src/
OBJ_DIR =		obj/
LIB_DIR =		libft/
ASM_DIR =		asm/

SRC		=		main.c woody.c load_file.c error.c elf64.c swap_bits.c write_file.c find.c key.c cryptography.c
OBJ		=		$(addprefix $(OBJ_DIR),$(SRC:.c=.o))
LIB		=		libft/libft.a

SRC_ASM		=		encrypt.s
OBJ_ASM		=		$(addprefix $(OBJ_DIR),$(SRC_ASM:.s=.o))

all: $(WOODY) $(DECRYPT)

$(DECRYPT): $(ASM_DIR)decrypt.s
	@echo "Compiling decrypt"
	@$(ASM) $(ASMFLAGS) $^
	@ld -o $(ASM_DIR)$@ $(ASM_DIR)decrypt.o

$(WOODY): $(LIB) $(OBJ) $(OBJ_ASM)
	@echo "Compiling woody_woodpacker"
	@$(CC) $(CFLAGS) $(INC) $(LIB) -o $@ $^
	@echo "Done."

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(OBJ_ASM): $(OBJ_DIR)%.o: $(ASM_DIR)%.s
	@$(ASM) $(ASMFLAGS) $< -o $@

$(LIB):
	@echo "Compiling libft"
	@make -C $(LIB_DIR)
	@echo "Done."

clean:
	@echo "Cleaning objects"
	@rm -f $(OBJ)
	@make clean -C $(LIB_DIR)

fclean: clean
	@echo "Cleaning executable."
	@rm -f $(WOODY) woody
	@make fclean -C $(LIB_DIR)

re: fclean all

