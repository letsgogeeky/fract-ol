NAME:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -g -fsanitize=address

BACKEND_SRCS := backend/ft_complex/arithmetic.c backend/ft_complex/utils.c backend/fractol.c
FRONTEND_SRCS := frontend/controls/keyboard.c frontend/controls/mouse.c frontend/controls/window.c \
	frontend/colors/draw.c
SRCS := main.c

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