NAME	=		woody_woodpacker

CC 		=		gcc
CFLAGS	= 		-Wall -Werror -Wextra
INC		=		-I ./inc -I libft/

SRC_DIR =		src/
OBJ_DIR =		obj/
LIB_DIR =		libft/

SRC		=		main.c woody.c load_file.c error.c elf64.c swap_bits.c write_file.c find.c key.c
OBJ		=		$(addprefix $(OBJ_DIR),$(SRC:.c=.o))
LIB		=		libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Compiling woody_woodpacker"
	@$(CC) $(CFLAGS) $(INC) $(LIB) -o $@ $^
	@echo "Done."


$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	@echo "Compiling libft"
	@make -C $(LIB_DIR)
	@echo "Done."

clean:
	@echo "Cleaning objects"
	@rm -f $(OBJ)

fclean: clean
	@echo "Cleaning executable."
	@rm -f $(NAME) woody

re: fclean all

