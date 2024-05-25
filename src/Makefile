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
DIR_PARSER		= source/parser/
DIR_GUI			= source/gui/

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

FILES_INTERSECT	=	intersect_cylinder.c \
					intersect_cylinder_2.c \
					intersect_plane.c \
					intersect_sphere.c \
					intersect_utils.c \
					intersect_world.c \
					intersect.c

FILES_RAYTRACING	=	hit.c \
						lighting.c \
						prepare_computations.c \
						ray_for_pixel.c \
						ray.c \
						reflect.c \
						shade_hit.c \
						shadow.c \
						transform.c

FILES_NORMAL	=	normal_plane.c \
					normal_cylinder.c \
					normal_sphere.c \
					normal.c

FILES_CANVAS	=	canvas.c \
					canvas_2.c

FILES_SHAPE	=	material.c \
				shape_sphere.c \
				shape_cylinder.c \
				shape.c

FILES_SOURCES	=	check_params.c \
					exit.c \
					file.c \
					messages.c \
					minirt_utils.c \
					main.c

FILES_WORLD		=	camera.c \
					light.c \
					view_transform.c \
					world.c

FILES_PARSE		= 	lexer.c \
					peek.c \
					token_2.c \
					token_3.c \
					token.c

FILES_GUI		=	event_keyboard.c \
					event_window.c	\
					frame.c \
					window.c

# =============== INCLUDES FILES ===============
INCLUDES =	includes/ \
			includes/array/ \
			includes/errors/ \
			includes/parser/ \
			includes/raytracing/ \
			includes/raytracing/canvas/ \
			includes/raytracing/color/ \
			includes/raytracing/intersect/ \
			includes/raytracing/normal/ \
			includes/raytracing/matrix/ \
			includes/raytracing/shape/  \
			includes/raytracing/world/ \
			includes/gui/

# =============== SOURCES FILES + ITS DIRECTORIES ===============
ARRAY_F			= $(addprefix $(DIR_ARRAY), $(FILES_ARRAY))
CANVAS_F		= $(addprefix $(DIR_CANVAS), $(FILES_CANVAS))
COLOR_F			= $(addprefix $(DIR_COLOR), $(FILES_COLOR))
ERRORS_F		= $(addprefix $(DIR_ERRORS), $(FILES_ERRORS))
MATRIX_F		= $(addprefix $(DIR_MATRIX), $(FILES_MATRIX))
INTERSECT_F		= $(addprefix $(DIR_INTERSECT), $(FILES_INTERSECT))
RAYTRACING_F	= $(addprefix $(DIR_RAYTRACING), $(FILES_RAYTRACING))
PARSER_F		= $(addprefix $(DIR_PARSER), $(FILES_PARSE))
SHAPE_F			= $(addprefix $(DIR_SHAPE), $(FILES_SHAPE))
NORMAL_F		= $(addprefix $(DIR_NORMAL), $(FILES_NORMAL))
SOURCES_F		= $(addprefix $(DIR_SOURCE), $(FILES_SOURCES))
WORLD_F			= $(addprefix $(DIR_WORLD), $(FILES_WORLD))
GUI_F			= $(addprefix $(DIR_GUI), $(FILES_GUI))

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))

SOURCES =	$(ARRAY_F) $(CANVAS_F) $(COLOR_F) $(ERRORS_F) $(GUI_F) $(INTERSECT_F) $(MATRIX_F) $(NORMAL_F)
SOURCES +=	$(PARSER_F) $(RAYTRACING_F) $(SHAPE_F) $(SOURCES_F) $(WORLD_F)
OBJECTS =	$(SOURCES:.c=.o)
DEPENDS =	$(SOURCES:.c=.d)











# =============== RECIPES ===============

all : $(NAME)

$(NAME) : $(LIBS) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBFT_A) $(LIBML_A) -lXext -lX11 -lm

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES_F) -I$(DIR_LIBFT) -MMD -c $< -o $@

-include $(DEPENDS)

$(LIBS) :
	$(MAKE) -C $(DIR_LIBFT) rebonus
	$(MAKE) -C $(DIR_MLX)

clean :
	$(MAKE) -C $(DIR_LIBFT) clean
	# $(MAKE) -C $(DIR_MLX) clean
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)
#$(RM) $(OBJECTS_BONUS)
#$(RM) $(DEPENDS_BONUS)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

# bonus : $(LIBS) $(OBJECTS_BONUS)
# define WIDTH 800
# define HEIGHT 600
# define WIN_TIT "miniRT"

# 	$(CC) $(FLAGS) $(OBJECTS_BONUS) -o $(NAME) $(LIBFT_A) $(LIBML_A) -lXext -lX11 -lm -DBONUS

.PHONY : all clean fclean re bonus