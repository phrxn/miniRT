NAME = test.out

LIBFT_DIR = ../src/libs/libft/
ASSERTZ_DIR = assertz/


LIBFT   = $(LIBFT_DIR)libft.a
ASSERTZ = $(ASSERTZ_DIR)assertz.a


CC = gcc


FLAGS = -Wall -Werror -Wextra


# ==================================================

# **************************** SOURCES ****************************

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
					minirt.c

FILES_WORLD		=	camera.c \
					light.c \
					view_transform.c \
					world.c

FILES_PARSE		= 	lexer.c \
					peek.c \
					token_2.c \
					token_3.c \
					token.c

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
			includes/raytracing/world/

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

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))

SOURCES =	$(ARRAY_F) $(CANVAS_F) $(COLOR_F) $(ERRORS_F) $(INTERSECT_F) $(MATRIX_F) $(NORMAL_F)
SOURCES +=	$(PARSER_F) $(RAYTRACING_F) $(SHAPE_F) $(SOURCES_F) $(WORLD_F)
OBJECTS =	$(SOURCES:.c=.o)
DEPENDS =	$(SOURCES:.c=.d)





















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
			print_object.c \
			dworld.c

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

$(NAME) : $(S_OBJECTS) $(T_OBJECTS) $(D_OBJECTS) $(ASSERTZ) $(LIBFT)
	$(CC) $(S_OBJECTS) $(T_OBJECTS) $(D_OBJECTS) -o $@  $(ASSERTZ) $(LIBFT) -lm

%.o : %.c
	$(CC) $(FLAGS) $(T_INCLUDES_F) $(S_INCLUDES_F) $(D_INCLUDES_F) -I$(ASSERTZ_DIR) -I$(LIBFT_DIR) -DALL -DTEST -MMD -c $< -o $@

fclean :
	rm -rf $(NAME)
	rm -rf $(T_OBJECTS)
	rm -rf $(T_DEPENDS)
	rm -rf $(S_OBJECTS)
	rm -rf $(S_DEPENDS)
	make -C $(ASSERTZ_DIR) clean
	make -C $(LIBFT_DIR) fclean

$(LIBFT) :
	make -C $(LIBFT_DIR) bonus

$(ASSERTZ) :
	make -C $(ASSERTZ_DIR)

-include $(D_DEPENDS)
-include $(S_DEPENDS)
-include $(T_DEPENDS)

.PHONY : all clean fclean re bonus