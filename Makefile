NAME:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -g -O3 -march=corei7 -funroll-loops -pthread
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address -flto -framework Cocoa -framework OpenGL -framework IOKit

BACKEND_SRCS := backend/ft_complex/arithmetic.c backend/ft_complex/utils.c backend/fractol.c \
	backend/environment.c backend/ft_complex/manage.c
FRONTEND_SRCS := frontend/controls/mouse.c frontend/controls/window.c \
	frontend/colors/draw.c frontend/colors/encoders.c frontend/controls/keyboard/factory.c \
	frontend/controls/keyboard/shift_color.c frontend/controls/keyboard/shift_details.c \
	frontend/controls/keyboard/shift_range.c
SRCS := init.c main.c

OBJS := ${addprefix src/, ${BACKEND_SRCS:.c=.o} ${FRONTEND_SRCS:.c=.o} ${SRCS:.c=.o}}


all: MLX ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && echo "Successful build...!"

MLX:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -f fractol

re: fclean all