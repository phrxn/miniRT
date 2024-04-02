NAME = test.out

LIBFT_DIR = ../src/libs/libft/
ASSERTZ_DIR = ./assertz/


LIBFT   = $(LIBFT_DIR)libft.a
ASSERTZ = $(ASSERTZ_DIR)assertz.a

SOURCES_PROGRAM  = \
			     ../src/source/matrix.c



SOURCES_TESTS    = \
					src/source/matrix_test.c


SOURCES :=	$(SOURCES_PROGRAM)\
			$(SOURCES_TESTS)\
			main.c

CC = gcc

OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)

# recipes

all : $(NAME)

$(NAME) : $(ASSERTZ) $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) -o $@  $(ASSERTZ) $(LIBFT)

%.o : %.c
	$(CC) -MMD -c $< -o $@ -DALL -I../src/includes/ -I./assertz/ -I$(LIBFT_DIR) -DTEST

-include $(DEPENDS)

fclean :
	rm -rf $(NAME)
	rm -rf $(OBJECTS)
	rm -rf $(DEPENDS)
	make -C $(ASSERTZ_DIR) clean
	make -C $(LIBFT_DIR) fclean

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(ASSERTZ) :
	make -C $(ASSERTZ_DIR)