# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhille <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/23 11:55:15 by jhille        #+#    #+#                  #
#    Updated: 2021/11/27 20:12:28 by jhille        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

ALL_FILES = $(MAIN_FILES) $(PARSING_FILES) $(TRANSLATE_FILES)\
			$(MATRIX_FILES) $(PTR_MAN_FILE) $(RAY_FILES)\
			$(TUPLE_FILES) $(SCENE_FILES) $(COLOR_FILES) $(RENDER_FILES)

MAIN_FILES = main.c\
		rt_error_exit.c

PARSING_FILES = parsing/rt_argparse.c\
				parsing/rt_set_utils.c\
				parsing/ft_atof.c\
				parsing/char_ptrlen.c\
				parsing/amb_set.c\
				parsing/cam_set.c\
				parsing/res_set.c\
				parsing/light_set.c\
				parsing/sphere_set.c\
				parsing/plane_set.c\
				parsing/cylin_set.c\
				parsing/parse_values_from_str.c

TRANSLATE_FILES = translate_data/translate_data.c\
				translate_data/get_world.c\
				translate_data/get_camera.c\
				translate_data/get_sphere.c\
				translate_data/get_plane.c\
				translate_data/get_cylinder.c\
				translate_data/get_light.c\
				translate_data/get_rotation.c\
				translate_data/free_data.c

MATRIX_FILES = matrix/rt_matrices.c\
				matrix/rt_matrix_compare.c\
				matrix/rt_matrix_determinant.c\
				matrix/rt_matrix_free.c\
				matrix/rt_matrix_identity.c\
				matrix/rt_matrix_inversion.c\
				matrix/rt_matrix_multiply.c\
				matrix/rt_matrix_rotation.c\
				matrix/rt_matrix_scaling.c\
				matrix/rt_matrix_shearing.c\
				matrix/rt_matrix_translation.c\
				matrix/rt_matrix_transpose.c\
				matrix/rt_matrix_x_tuple.c\
				matrix/rt_sub_matrix.c

TUPLE_FILES = tuples/tuple_calc.c\
				tuples/tuple_ini.c\
				tuples/tuple_negate.c\
				tuples/tuple_product.c\
				tuples/tuple_vector.c\

RAY_FILES = rays/epsilon.c\
			rays/lighting.c\
			rays/material.c\
			rays/normal_at.c\
			rays/sphere_normal_at.c\
			rays/cylinder_normal_at.c\
			rays/point_light.c\
			rays/ray_hit.c\
			rays/ray_ini.c\
			rays/global_intersect.c\
			rays/sphere_intersect.c\
			rays/plane_intersect.c\
			rays/cylinder_intersect.c\
			rays/intersect_array_free.c\
			rays/ray_position.c\
			rays/ray_transform.c\
			rays/reflect.c\
			rays/sphere_set_transform.c\
			rays/ray_free.c\
			rays/square.c

SCENE_FILES = scene/camera.c\
				scene/color_at.c\
				scene/intersect_world.c\
				scene/prep_computations.c\
				scene/ray_for_pixel.c\
				scene/shade_hit.c\
				scene/view_transform.c\
				scene/world.c\
				scene/is_shadowed.c\
				scene/radian.c

COLOR_FILES = color/color_ini.c\
				color/trgb.c\
				color/convert_color.c\
				color/color_mult.c

RENDER_FILES = render/render_world.c\
				render/mlx_ini.c\
				render/pixel_put.c

HEADER_FILES = matrix/rt_matrix.h\
				scene/scene.h\
				tuples/tuples.h\
				ptr_management/assign_free.c\
				rays/rays.h\
				color/color.h\
				parsing/parsing.h\
				render/render.h\
				minirt.h


PTR_MAN_FILE = ptr_management/ft_assign_free.c

LIBFT = libft.a

CFLAGS = -Wextra -Wall -Werror

OBJ = $(ALL_FILES:.c=.o)

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLX = libmlx.a
	LINKING = libmlx.a -lm -lX11 -lXext
else
	MLX = libmlx.dylib
	LINKING = -L. -lmlx -framework OpenGL -framework AppKit
endif

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) libft/$(LIBFT) $(LINKING) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make bonus -C libft

$(MLX):
	make -C mlx
	cp mlx/$(MLX) .

clean:
	rm -f $(OBJ)
	make fclean -C libft
	make clean -C mlx

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re make
