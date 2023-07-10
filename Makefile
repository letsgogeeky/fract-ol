NAME:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX := ./lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS := main.c
OBJS := ${addprefix src/, ${SRCS:.c=.o}}


all: MLX ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && echo "Good Job!"

MLX:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -f fractol