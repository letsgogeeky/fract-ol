NAME:= fractol
CFLAGS	:= -Wextra -Wall -Werror -g -O3 -funroll-loops
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a 
LDFLAGS := -ldl -L $(LIBMLX)/glfw_lib/ -lglfw3 -pthread -lm -fsanitize=address -flto -framework Cocoa -framework OpenGL -framework IOKit
BACKEND_SRCS := backend/ft_complex/arithmetic.c backend/ft_complex/utils.c backend/fractol.c
FRONTEND_SRCS := frontend/controls/keyboard.c frontend/controls/mouse.c frontend/controls/window.c \
	frontend/colors/draw.c frontend/colors/encoders.c
SRCS := init.c main.c

OBJS := ${addprefix src/, ${BACKEND_SRCS:.c=.o} ${FRONTEND_SRCS:.c=.o} ${SRCS:.c=.o}}

all: MLX ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(LDFLAGS) -o $(NAME) && echo "Successful build...!"


MLX: DEPS
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

DEPS:
	chmod 755 setup_libs.sh
	sh setup_libs.sh

clean:
	@rm -rf $(OBJS)

fclean: clean
	rm -f fractol

re: fclean all