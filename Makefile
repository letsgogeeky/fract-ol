NAME:= fractol

SRC:= main.c

all: ${NAME}

${NAME}: MLX

MLX: 
	@cmake -B build lib/MLX42
	@make HEADERS='-I lib/glfw-3.3.8/include' -C lib/MLX42/build