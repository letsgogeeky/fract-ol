NAME:= fractol

CFLAGS	:= -Wextra -Wall -Werror -g -O3 -funroll-loops
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a 
LDFLAGS := -ldl -L $(LIBMLX)/glfw_lib/ -lglfw3 -pthread -lm -fsanitize=address -flto -framework Cocoa -framework OpenGL -framework IOKit
BACKEND_SRCS := backend/ft_complex/arithmetic.c backend/fractol.c \
	backend/environment.c backend/ft_complex/manage.c
FRONTEND_SRCS := frontend/controls/mouse.c frontend/controls/window.c \
	frontend/colors/draw.c frontend/colors/encoders.c frontend/controls/keyboard/factory.c \
	frontend/controls/keyboard/shift_color.c frontend/controls/keyboard/shift_details.c \
	frontend/controls/keyboard/shift_range.c

SRCS := init.c main.c

OBJS := ${addprefix src/, ${BACKEND_SRCS:.c=.o} ${FRONTEND_SRCS:.c=.o} ${SRCS:.c=.o}}

all: MLX ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME) && echo "Successful build...!"


MLX:
	chmod 755 setup_libs.sh
	sh setup_libs.sh

rmlib:
	rm -rf lib/MLX42

clean:
	@rm -rf $(OBJS)

fclean: clean
	rm -f fractol

re: fclean all

.PHONY: all rmlib clean fclean re