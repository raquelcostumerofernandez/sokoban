##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make library
##

CC=gcc

CFLAGS=-Werror -Wall -Wextra

C_FILES = src/basic/my_strupcase.c \
 			src/basic/my_getnbr.c \
 			src/basic/my_str_islower.c \
 			src/basic/my_str_to_word_array.c \
 			src/basic/my_str_isnum.c \
 			src/basic/my_strcpy.c \
 			src/basic/my_put_nbr.c \
 			src/basic/my_strcmp.c \
 			src/basic/my_find_prime_sup.c \
 			src/basic/my_isneg.c \
 			src/basic/convert_base.c \
 			src/basic/my_strlowcase.c \
 			src/basic/my_show_word_array.c \
 			src/basic/my_swap.c \
 			src/basic/my_showstr.c \
 			src/basic/my_compute_square_root.c \
 			src/basic/my_strncmp.c \
 			src/basic/my_str_isprintable.c \
 			src/basic/my_showmem.c \
 			src/basic/my_is_prime.c \
 			src/basic/my_putstr.c \
 			src/basic/my_strcat.c \
 			src/basic/my_strncpy.c \
 			src/basic/my_sort_int_array.c \
 			src/basic/my_strdup.c \
 			src/basic/my_strlen.c \
 			src/basic/my_putchar.c \
 			src/basic/my_strcapitalize.c \
 			src/basic/my_getnbr_base.c \
 			src/basic/my_strncat.c \
 			src/basic/my_revstr.c \
 			src/basic/my_strstr.c \
 			src/basic/my_str_isalpha.c \
 			src/basic/my_str_isupper.c \
 			src/basic/my_putnbr_base.c \
 			src/basic/my_compute_power_rec.c\
			src/basic/my_memcmp.c \
			src/basic/my_memset.c \
			src/basic/my_strchr.c \
			src/basic/my_strrchr.c \
			src/basic/my_memcpy.c \
			src/basic/my_strjoin.c \
			src/printf/genericf.c \
			src/printf/f_functions.c \
			src/printf/parameter_utils.c \
			src/printf/utils1.c \
			src/printf/utils2.c \
			src/printf/utils3.c \
			src/linked_lists/basic_list.c \
			src/linked_lists/simple_operations.c \
			src/linked_lists/iter_tools.c \
			src/linked_lists/modifications.c \
			src/engine/creation.c \
			src/engine/destruction.c \
			src/engine/ticks.c \
			src/engine/finder.c \
			src/engine/sprite_helper.c \
			src/engine/fps_controller.c \
            src/engine/sprite_creation.c \


O_FILES = $(C_FILES:.c=.o)

HEADERS = include/my.h \
			include/structs.h

EXTERN_H = $(subst include/,../../include/,$(HEADERS))

NAME=libmy.a

$(NAME): $(O_FILES)
	ar -rsc $(NAME) $(O_FILES)
	cp $(NAME) ../
	mkdir -p ../../include
	cp $(HEADERS) ../../include

all: $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f ../$(NAME)
	rm -f $(EXTERN_H)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
