# =============== VARIABLES ===============

NAME = miniRT

CC = cc

FLAGS = -Wall -Werror -Wextra

DEFINES = -DBONUS=1

# ==================================================

# ++++++++++ SOURCES DIRECTORIES ++++++++++

DIR_SOURCE			= source/
DIR_ARRAY			= source/array/
DIR_ERRORS			= source/errors/
DIR_RAYTRACING		= source/raytracing/
DIR_CANVAS			= source/raytracing/canvas/
DIR_COLOR			= source/raytracing/color/
DIR_INTERSECT		= source/raytracing/intersect/
DIR_MATRIX			= source/raytracing/matrix/
DIR_NORMAL			= source/raytracing/normal/
DIR_SHAPE			= source/raytracing/shape/
DIR_WORLD			= source/raytracing/world/
DIR_PARSER			= source/parser/
DIR_LEXER			= source/parser/lexer/
DIR_GRAMMAR			= source/parser/grammar/
DIR_SYNTAX			= source/parser/grammar/syntax/
DIR_S_ELEMENTS		= source/parser/grammar/syntax/elements/
DIR_VALUES			= source/parser/grammar/values/
DIR_V_ELEMENTS		= source/parser/grammar/values/elements/
DIR_CONVERT			= source/parser/convert/
DIR_PARSER_WORLD	= source/parser/world/
DIR_BUILD_ELEMENTS	= source/parser/world/elements/
DIR_BUILD_SHAPES	= source/parser/world/elements/build_shapes/
DIR_GUI				= source/gui/

# ++++++++++ LIBRARIES DIRECTORIES ++++++++++
DIR_LIBS	= libs/
DIR_LIBFT	= $(DIR_LIBS)libft/
DIR_MLX		= $(DIR_LIBS)minilibx-linux/


# =============== LIBRARIES ===============
LIBFT_A = $(DIR_LIBFT)libft.a
LIBML_A = $(DIR_MLX)libmlx.a
LIBS = $(LIBFT_A) $(LIBML_A)


# =============== SOURCES FILES ===============

FILES_ERRORS 		=	build_world_errors.c \
						count_elements_errors.c \
						matrix_errors.c \
						parser_errors.c

FILES_ARRAY 		=	array.c

FILES_COLOR 		=	color_operations.c \
						color.c

FILES_MATRIX		=	matrix_alloc_2.c \
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

FILES_INTERSECT		=	intersect_cylinder.c \
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

FILES_NORMAL		=	normal_plane.c \
						normal_cylinder.c \
						normal_sphere.c \
						normal.c

FILES_CANVAS		=	canvas.c \
						canvas_2.c

FILES_SHAPE			=	material.c \
						shape_sphere.c \
						shape.c

FILES_SOURCES		=	check_params.c \
						exit.c \
						file.c \
						messages.c \
						minirt_utils.c \
						main.c

FILES_WORLD			=	ambient.c \
						camera.c \
						light.c \
						view_transform.c \
						world.c

FILES_PARSE			= 	count_elements.c \
						line.c \
						parser.c \
						token_2.c \
						token_3.c \
						token.c \
						transformation.c

FILES_SHAPE			=	material.c \
						shape_sphere.c \
						shape_cylinder.c \
						shape.c

FILES_LEXER			=	lexer_2.c \
						lexer_3.c \
						lexer.c \
						peek.c

FILES_GRAMMAR		=	check_grammar.c \
						dictionary_2.c \
						dictionary.c \
						select_element.c

FILES_SYNTAX		=	check_syntax.c \
						properties_syntax_2.c \
						properties_syntax.c

FILES_S_ELEMENTS	=	syntax_ambient.c \
						syntax_camera.c \
						syntax_cylinder.c \
						syntax_light.c \
						syntax_plane.c \
						syntax_sphere.c

FILES_CONVERT		=	ft_atof.c \
						ft_atoi_2.c \
						matrix_rotation_convert.c \
						property_convert_2.c \
						property_convert.c

FILES_VALUES		=	check_values.c \
						properties_values_2.c \
						properties_values.c

FILES_V_ELEMENTS	=	values_ambient.c \
						values_camera.c \
						values_cylinder.c \
						values_light.c \
						values_plane.c \
						values_sphere.c

FILES_WORLD			=	ambient.c \
						camera.c \
						light.c \
						view_transform.c \
						world.c

FILES_PARSER_WORLD	=	build_world.c

FILES_BUILD_ELEMENTS	=	build_element_ambient.c \
							build_element_camera.c \
							build_element_light.c \
							build_element_shape.c \
							build_element.c

FILES_BUILD_SHAPE		=	build_shape_cylinder.c \
							build_shape_plane.c \
							build_shape_sphere.c \
							commons_build.c

FILES_GUI		=	event_keyboard.c \
					event_window.c	\
					frame.c \
					window.c

# =============== INCLUDES FILES ===============
INCLUDES =	$(DIR_MLX) \
			includes/ \
			includes/array/ \
			includes/errors/ \
			includes/parser/ \
			includes/parser/grammar/ \
			includes/parser/convert/ \
			includes/parser/grammar/syntax/ \
			includes/parser/grammar/syntax/elements/ \
			includes/parser/grammar/values/ \
			includes/parser/grammar/values/elements/ \
			includes/parser/lexer/ \
			includes/parser/world/ \
			includes/parser/world/elements/ \
			includes/parser/world/elements/build_shapes/ \
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
GRAMMAR_F		= $(addprefix $(DIR_GRAMMAR), $(FILES_GRAMMAR))
LEXER_F			= $(addprefix $(DIR_LEXER), $(FILES_LEXER))
SYNTAX_F		= $(addprefix $(DIR_SYNTAX), $(FILES_SYNTAX))
ELEMENTS_S_F	= $(addprefix $(DIR_S_ELEMENTS), $(FILES_S_ELEMENTS))
VALUES_F		= $(addprefix $(DIR_VALUES), $(FILES_VALUES))
ELEMENTS_V_F	= $(addprefix $(DIR_V_ELEMENTS), $(FILES_V_ELEMENTS))
CONVERT_F		= $(addprefix $(DIR_CONVERT), $(FILES_CONVERT))
PARSER_WORLD_F	= $(addprefix $(DIR_PARSER_WORLD), $(FILES_PARSER_WORLD))
BUILD_ELEMENTS  = $(addprefix $(DIR_BUILD_ELEMENTS), $(FILES_BUILD_ELEMENTS))
BUILD_SHAPES	= $(addprefix $(DIR_BUILD_SHAPES), $(FILES_BUILD_SHAPE))
GUI_F			= $(addprefix $(DIR_GUI), $(FILES_GUI))

# =============== INCLUDES FILES + ITS DIRECTORIES ===============
INCLUDES_F = $(addprefix -I, $(INCLUDES))

SOURCES =	$(ARRAY_F) $(BUILD_SHAPES) $(BUILD_ELEMENTS) $(CANVAS_F) $(COLOR_F) $(CONVERT_F) $(ELEMENTS_S_F) $(ELEMENTS_V_F) $(ERRORS_F) $(GRAMMAR_F)
SOURCES +=	$(GUI_F) $(LEXER_F) $(INTERSECT_F) $(MATRIX_F) $(NORMAL_F) $(PARSER_F) $(PARSER_WORLD_F) $(RAYTRACING_F) $(VALUES_F)
SOURCES +=	$(SHAPE_F) $(SOURCES_F) $(SYNTAX_F) $(WORLD_F)
OBJECTS =	$(SOURCES:.c=.o)
DEPENDS =	$(SOURCES:.c=.d)

# =============== RECIPES ===============

all : $(NAME)

$(NAME) : $(LIBS) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBFT_A) $(LIBML_A) -lXext -lX11 -lm

%.o : %.c
	$(CC) $(FLAGS) $(DEFINES) $(INCLUDES_F) -I$(DIR_LIBFT) -MMD -c $< -o $@

$(LIBS) :
	$(MAKE) -C $(DIR_LIBFT) rebonus
	$(MAKE) -C $(DIR_MLX)


clean :
	$(MAKE) -C $(DIR_LIBFT) clean
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

-include $(DEPENDS)

.PHONY : all clean fclean re bonus