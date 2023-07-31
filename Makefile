NAME:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -g -O3 -march=corei7 -funroll-loops
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
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(LDFLAGS) $(HEADERS) -o $(NAME) && echo "Successful build...!"


MLX:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
# echo "Installing GLFW"
# curl -LO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip
# unzip glfw-3.3.8.bin.MACOS.zip
# rm glfw-3.3.8.bin.MACOS.zip
# mv glfw-3.3.8.bin.MACOS/lib-universal glfw-3.3.8.bin.MACOS/glfw_lib
# mv glfw-3.3.8.bin.MACOS/glfw_lib ./lib/MLX42/
# rm -rf glfw-3.3.8.bin.MACOS


clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -f fractol

re: fclean all