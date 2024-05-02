# =============== VARIABLES ===============

NAME = miniRT

CC = cc

FLAGS = -Wall -Werror -Wextra

# =============== DIRECTORIES ===============

# ++++++++++ SOURCES ++++++++++
DIR_SOURCE		= source/
DIR_ARRAY		= source/array/
DIR_ERRORS		= source/errors/
DIR_RAYTRACING	= source/raytracing/
DIR_INTERSECT	= source/raytracing/intersect/
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

FILES_ARRAY  = array.c

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

FILES_INTERSECT = intersect_sphere.c \
				intersect_utils.c

FILES_RAYTRACING =	ray.c \
					hit.c \
					transform.c \
					world.c

FILES_CANVAS = canvas.c

FILES_SOURCES = check_params.c \
				exit.c \
				file.c \
				messages.c \
				minirt.c \
				main.c

# =============== INCLUDES FILES ===============
INCLUDES =	includes/ \
			includes/array/ \
			includes/errors/ \
			includes/raytracing/ \
			includes/raytracing/canvas \
			includes/raytracing/intersect \
			includes/raytracing/matrix/

# =============== SOURCES FILES + ITS DIRECTORIES ===============
ARRAY_F			= $(addprefix $(DIR_ARRAY), $(FILES_ARRAY))
ERRORS_F		= $(addprefix $(DIR_ERRORS), $(FILES_ERRORS))
MATRIX_F		= $(addprefix $(DIR_MATRIX), $(FILES_MATRIX))
INTERSECT_F		= $(addprefix $(DIR_INTERSECT), $(FILES_INTERSECT))
RAYTRACING_F	= $(addprefix $(DIR_RAYTRACING), $(FILES_RAYTRACING))
CANVAS_F		= $(addprefix $(DIR_CANVAS), $(FILES_CANVAS))
SOURCES_F		= $(addprefix $(DIR_SOURCE), $(FILES_SOURCES))

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))

SOURCES = $(ERRORS_F) $(SOURCES_F) $(MATRIX_F) $(CANVAS_F) $(RAYTRACING_F)
SOURCES += $(INTERSECT_F) $(ARRAY_F)
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)










# =============== RECIPES ===============

all : $(NAME)

$(NAME) : $(LIBS) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@ $(LIBFT_A) $(LIBML_A) -lXext -lX11 -lm

%.o : %.c
	$(CC) $(INCLUDES_F) -I$(DIR_LIBFT) -MMD -c $< -o $@

-include $(DEPENDS)

$(LIBS) :
	$(MAKE) -C $(DIR_LIBFT) rebonus
	$(MAKE) -C $(DIR_MLX)

clean :
	$(MAKE) -C $(DIR_LIBFT) clean
	$(MAKE) -C $(DIR_MLX) clean
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)
#$(RM) $(OBJECTS_BONUS)
#$(RM) $(DEPENDS_BONUS)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

# bonus : $(LIBS) $(OBJECTS_BONUS)
# 	$(CC) $(FLAGS) $(OBJECTS_BONUS) -o $(NAME) $(LIBFT_A) $(LIBML_A) -lXext -lX11 -lm -DBONUS

.PHONY : all clean fclean re bonus