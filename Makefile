NAME	= miniRT
LIBX	= minilibX
# LIBTST	= tests
# DIST	= debug

CC		= /usr/bin/gcc
DBG		= valgrind
RM		= /bin/rm

SRCDIR	= srcs
BLDDIR	= bin
OBJDIR	= bin
INCDIR	= includes
# TSTDIR	= tests

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
IFLAGS	= -I$(INCDIR) -I$(LIBX)

OS		= $(shell uname)

ifeq ($(OS), Linux)
LFLAGS	= -L$(LIBX)
lFLAGS 	=  -lmlx -lX11 -lXext -lm -lpthread 
endif
ifeq ($(OS), Darwin)
LFLAGS	= -framework AppKit -framework OpenGL -lpthread 
lFLAGS	= -lz -lm
endif

# LOG		= err.log

MAIN	= $(SRCDIR)/raytracer/main.c

SRCS	= $(addprefix $(SRCDIR)/, \
			$(addprefix allocations/, create_cube.c create_pyramid.c freeall.c new_cone.c \
				new_cube.c new_cylinder.c new_disk.c new_object.c new_plane.c new_pyramid.c \
				new_scene.c new_sphere.c new_square.c new_triangle.c) \
			$(addprefix aux/, aux1.c aux2.c aux3.c aux4.c split_multicharset.c) \
			$(addprefix color/, color1.c color2.c) \
			$(addprefix gnl/, get_next_line_utils.c get_next_line.c) \
			$(addprefix hooks/, change_dir_obj.c change_dir_pos_obj2.c change_pos_obj.c fill.c keys.c mouse.c \
				obj_next.c obj_back.c) \
			$(addprefix parsing/, parse_obj_bonus_properties.c rt_check_file.c rt_parse_error1.c \
				rt_parse_error2.c rt_parse_error3.c rt_parse_error4.c rt_parse_error5.c rt_parse_in_lst.c rt_parse.c) \
			$(addprefix raytracer/, collisions.c effects.c engine_hooks.c engine.c error.c export_bmp.c \
				load_image_hooks.c load_image.c parser.c uvmapping.c) \
			$(addprefix shapes/, cone.c cylinder_collisions.c normals.c plane_collisions.c sphere_collisions.c \
				square_collisions.c triangle_collisions.c) \
			$(addprefix vector/, vec3.c vec3basics1.c vec3basics2.c vec3rot.c) \
			)

OBJS	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS) $(MAIN))
OBJDS	= $(addprefix $(OBJDIR)/, allocations aux color gnl hooks parsing raytracer shapes vector)

HDRS	= $(addprefix $(INCDIR)/, allocations.h aux.h ft_error.h ft_color.h get_next_line.h hooks.h raytracer.h \
			parsing.h shape.h vec3.h data.h)

# ifeq ($(DIST), debug)
#	CFLAGS += -g -DDIST_DEBUG
#	NAME := $(NAME)-debug
#endif

all:		$(NAME)

#debug:			all
#	@echo DBG $(NAME)
#	@$(DBG) ./$(NAME) 2>$(LOG)

#log:
#	tail -f $(LOG) 2>&1 | perl -ne 'if (/file truncated/) {system 'clear'; print} else {print}'

$(LIBX)/libmlx.a:
	make -C $(LIBX)

#libtest:
#	make -C $(LIBTST) libtest.a CC="$(CC)" CFLAGS="$(CFLAGS)"

# $(LIBX)/libmlx.a: libx
#$(LIBTST)/libtest.a: libtest

$(OBJDS):
	@echo MK $@
	mkdir -p $@

$(NAME):		$(LIBX)/libmlx.a $(OBJDS) $(OBJS)
	@echo LINK $(NAME)
	$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS) $(IFLAGS) $(OBJS) $(lFLAGS)

# test:			NAME := $(NAME)-test
# test:			LFLAGS += -Ltests -ltest
# test:			MAIN =
# test:			libtest $(OBJDS) $(OBJS) $(LIBFT)/libft.a
#	@echo LINK $(NAME)
#	$(CC) $(OBJS) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(NAME)
#	./$(NAME) 2>$(LOG)

$(OBJDIR):
	@echo MK $@
	@mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HDRS) Makefile
	@echo CC $<
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	make -C $(LIBX) $@
#	make -C $(LIBTST) $@
	@echo RM $(BLDDIR)
	@$(RM) -rf $(BLDDIR)

fclean:			clean
	make -C $(LIBX) $@
#	make -C $(LIBTST) $@
	@echo RM $(NAME)
#	@echo RM $(NAME)-test
#	@$(RM) -f $(NAME) $(NAME)-test
#	@echo RM test.dSYM
#	@$(RM) -rf test.dSYM

re:				fclean all

#test-dir:		$(OBJDIR)
#	@echo MK $(OBJDIR)/tests
#	@mkdir -p $(OBJDIR)/tests

.PHONY: clean fclean minilibX

$(VERBOSE).SILENT:
