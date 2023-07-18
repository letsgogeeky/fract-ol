NAME:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -g -fsanitize=address

COMPLEX_SRCS := ft_complex/arithmetic.c ft_complex/utils.c
SRCS := main.c

OBJS := ${addprefix src/, ${COMPLEX_SRCS:.c=.o} ${SRCS:.c=.o}}


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