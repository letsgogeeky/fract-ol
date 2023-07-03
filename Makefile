NAME:= fractol

SRC:= main.c

all: ${NAME}

${NAME}: MLX
	gcc main.c build/libmlx42.a -Iinclude -lglfw

MLX: 
	@cmake -B build lib/MLX42
	@make HEADERS='-I lib/glfw-3.3.8/include' -C ./build
