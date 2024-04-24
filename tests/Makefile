NAME = test.out

LIBFT_DIR = ../src/libs/libft/
ASSERTZ_DIR = assertz/


LIBFT   = $(LIBFT_DIR)libft.a
ASSERTZ = $(ASSERTZ_DIR)assertz.a


CC = gcc

# **************************** SOURCES ****************************
# =============== DIRECTORIES ===============


# ++++++++++ SOURCES ++++++++++
DIR_SOURCE		= source/
DIR_ERRORS		= source/errors/
DIR_RAYTRACING	= source/raytracing/
DIR_MATRIX		= source/raytracing/matrix/
DIR_CANVAS		= source/raytracing/canvas/

# ++++++++++ LIBRARIES ++++++++++
DIR_LIBS	= libs/
DIR_LIBFT	= $(DIR_LIBS)libft/
DIR_MLX		= $(DIR_LIBS)minilibx-linux/

# =============== LIBRARIES ===============
LIBFT_A = $(DIR_LIBFT)libft.a
LIBML_A = $(DIR_MLX)libmlx.a
LIBS = $(LIBFT_A) $(LIBML_A)


# =============== SOURCES FILES ===============
FILES_ERRORS =	matrix_errors.c

FILES_MATRIX =	matrix_alloc_2.c \
				matrix_alloc_3.c \
				matrix_alloc.c \
				matrix_fill_2.c \
				matrix_fill.c \
				matrix_operations_2.c \
				matrix_operations_3.c \
				matrix_operations_4.c \
				matrix_operations.c \
				matrix_utils.c \
				matrix.c

FILES_RAYTRACING = ray.c

FILES_CANVAS = canvas.c

FILES_SOURCES = check_params.c \
				exit.c \
				file.c \
				messages.c \
				minirt.c

# =============== INCLUDES FILES ===============
INCLUDES =	includes/ \
			includes/errors \
			includes/raytracing \
			includes/raytracing/canvas \
			includes/raytracing/matrix


# =============== SOURCES FILES + ITS DIRECTORIES ===============
ERRORS_F		= $(addprefix $(DIR_ERRORS), $(FILES_ERRORS))
MATRIX_F		= $(addprefix $(DIR_MATRIX), $(FILES_MATRIX))
RAYTRACING_F	= $(addprefix $(DIR_RAYTRACING), $(FILES_RAYTRACING))
CANVAS_F		= $(addprefix $(DIR_CANVAS), $(FILES_CANVAS))
SOURCES_F		= $(addprefix $(DIR_SOURCE), $(FILES_SOURCES))

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))


SOURCES = $(ERRORS_F) $(SOURCES_F) $(MATRIX_F) $(CANVAS_F) $(RAYTRACING_F)
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)






















# **************************** TESTS ****************************

S_SOURCES_DIR   = ../src/

# *** things in src directory ***
S_SOURCES = $(addprefix $(S_SOURCES_DIR), $(SOURCES))
S_OBJECTS = $(S_SOURCES:.c=.o)
S_DEPENDS = $(S_SOURCES:.c=.d)

S_INCLUDES_F = $(addprefix -I, $(addprefix $(S_SOURCES_DIR),$(INCLUDES)))

# *** things debug ***

D_SOURCES_DIR = ../debug/
D_INCLUDE_DIR = ../debug/

D_FILES =	compare.c \
			print_matrix.c

D_SOURCES = $(addprefix $(D_SOURCES_DIR), $(D_FILES))
D_OBJECTS = $(D_SOURCES:.c=.o)
D_DEPENDS = $(D_SOURCES:.c=.d)

D_INCLUDES_F =  $(addprefix -I, $(D_INCLUDE_DIR))

# *** the test file things

T_SOURCES = $(addprefix src/, $(SOURCES:.c=_test.c)) main.c
T_OBJECTS = $(T_SOURCES:.c=.o)
T_DEPENDS = $(T_SOURCES:.c=.d)

T_INCLUDES_F = $(addprefix -Isrc/, $(INCLUDES))

# recipes

all : $(NAME)

printz :
	@echo $(T_INCLUDES_F)

$(NAME) : $(S_OBJECTS) $(T_OBJECTS) $(D_OBJECTS) $(ASSERTZ) $(LIBFT)
	$(CC) $(S_OBJECTS) $(T_OBJECTS) $(D_OBJECTS) -o $@  $(ASSERTZ) $(LIBFT) -lm

%.o : %.c
	$(CC) $(T_INCLUDES_F) $(S_INCLUDES_F) $(D_INCLUDES_F) -I$(ASSERTZ_DIR) -I$(LIBFT_DIR) -DALL -DTEST -MMD -c $< -o $@

fclean :
	rm -rf $(NAME)
	rm -rf $(T_OBJECTS)
	rm -rf $(T_DEPENDS)
	rm -rf $(S_OBJECTS)
	rm -rf $(S_DEPENDS)
	make -C $(ASSERTZ_DIR) clean
	make -C $(LIBFT_DIR) fclean

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(ASSERTZ) :
	make -C $(ASSERTZ_DIR)

-include $(D_DEPENDS)
-include $(S_DEPENDS)
-include $(T_DEPENDS)

.PHONY : all clean fclean re bonus