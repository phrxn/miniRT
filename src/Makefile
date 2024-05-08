# =============== VARIABLES ===============

NAME = miniRT

CC = cc

FLAGS = -Wall -Werror -Wextra

# ==================================================

# ++++++++++ SOURCES DIRECTORIES ++++++++++
DIR_SOURCE		= source/
DIR_ARRAY		= source/array/
DIR_ERRORS		= source/errors/
DIR_RAYTRACING	= source/raytracing/
DIR_CANVAS		= source/raytracing/canvas/
DIR_COLOR		= source/raytracing/color/
DIR_INTERSECT	= source/raytracing/intersect/
DIR_MATRIX		= source/raytracing/matrix/
DIR_NORMAL		= source/raytracing/normal/
DIR_SHAPE		= source/raytracing/shape/
DIR_WORLD		= source/raytracing/world/

# ++++++++++ LIBRARIES DIRECTORIES ++++++++++
DIR_LIBS	= libs/
DIR_LIBFT	= $(DIR_LIBS)libft/
DIR_MLX		= $(DIR_LIBS)minilibx-linux/

# =============== LIBRARIES ===============
LIBFT_A = $(DIR_LIBFT)libft.a
LIBML_A = $(DIR_MLX)libmlx.a
LIBS = $(LIBFT_A) $(LIBML_A)


# =============== SOURCES FILES ===============
FILES_ERRORS =	matrix_errors.c

FILES_ARRAY = array.c

FILES_COLOR =	color_operations.c \
				color.c

FILES_MATRIX	=	matrix_alloc_2.c \
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

FILES_INTERSECT	=	intersect.c \
					intersect_sphere.c \
					intersect_utils.c

FILES_RAYTRACING	=	ray.c \
						hit.c \
						lighting.c \
						reflect.c \
						transform.c
						

FILES_NORMAL	=	normal.c \
					normal_sphere.c

FILES_CANVAS	=	canvas.c \
					canvas_2.c

FILES_SHAPE	=	material.c \
				shape_sphere.c \
				shape.c

FILES_SOURCES	=	check_params.c \
					exit.c \
					file.c \
					messages.c \
					minirt.c \
					main.c

FILES_WORLD		=	light.c \
					world.c

# =============== INCLUDES FILES ===============
INCLUDES =	includes/ \
			includes/array/ \
			includes/errors/ \
			includes/raytracing/ \
			includes/raytracing/canvas/ \
			includes/raytracing/color/ \
			includes/raytracing/intersect/ \
			includes/raytracing/normal/ \
			includes/raytracing/matrix/ \
			includes/raytracing/shape/  \
			includes/raytracing/world/

# =============== SOURCES FILES + ITS DIRECTORIES ===============
ARRAY_F			= $(addprefix $(DIR_ARRAY), $(FILES_ARRAY))
CANVAS_F		= $(addprefix $(DIR_CANVAS), $(FILES_CANVAS))
COLOR_F			= $(addprefix $(DIR_COLOR), $(FILES_COLOR))
ERRORS_F		= $(addprefix $(DIR_ERRORS), $(FILES_ERRORS))
MATRIX_F		= $(addprefix $(DIR_MATRIX), $(FILES_MATRIX))
INTERSECT_F		= $(addprefix $(DIR_INTERSECT), $(FILES_INTERSECT))
RAYTRACING_F	= $(addprefix $(DIR_RAYTRACING), $(FILES_RAYTRACING))
SHAPE_F			= $(addprefix $(DIR_SHAPE), $(FILES_SHAPE))
NORMAL_F		= $(addprefix $(DIR_NORMAL), $(FILES_NORMAL))
SOURCES_F		= $(addprefix $(DIR_SOURCE), $(FILES_SOURCES))
WORLD_F			= $(addprefix $(DIR_WORLD), $(FILES_WORLD))

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))

SOURCES =	$(ARRAY_F) $(CANVAS_F) $(COLOR_F) $(ERRORS_F) $(MATRIX_F) $(INTERSECT_F)
SOURCES +=	$(RAYTRACING_F) $(SHAPE_F) $(NORMAL_F) $(SOURCES_F) $(WORLD_F)
OBJECTS =	$(SOURCES:.c=.o)
DEPENDS =	$(SOURCES:.c=.d)











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