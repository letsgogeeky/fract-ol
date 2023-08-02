#!/bin/bash

OS_MAC="$(uname)"
OS_ARCH="$(uname -r)"

compile_mlx()
{
	echo "Compiling MLX42"
	cd lib/MLX42
	if command -v cmake &> /dev/null; then
		cmake -B build
		cmake --build build -j4
	else
		../../cmake-3.26.2-macos10.10-universal/CMake.app/Contents/bin/cmake -B build
		../../cmake-3.26.2-macos10.10-universal/CMake.app/Contents/bin/cmake --build build -j4
		rm -rf ../../cmake-3.26.2-macos10.10-universal
	fi
}
if [[ ! -d ./lib ]]; then
	mkdir ./lib
fi

if [[ -d ./lib/MLX42 ]]; then
	echo -e "\033[1;33m./lib/MLX42/ Exists\033[0m";
else
{
	git clone https://github.com/codam-coding-college/MLX42.git 
	mv MLX42 ./lib
	if [[ $OS_MAC == 'Darwin' ]]; then
		echo "Installing GLFW"
		curl -LO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip
		unzip glfw-3.3.8.bin.MACOS.zip
		rm glfw-3.3.8.bin.MACOS.zip
		mv glfw-3.3.8.bin.MACOS/lib-universal glfw-3.3.8.bin.MACOS/glfw_lib
		mv glfw-3.3.8.bin.MACOS/glfw_lib ./lib/MLX42/
		rm -rf glfw-3.3.8.bin.MACOS
	fi
	if [[ $OS_ARCH == *'arch'* ]]; then
		echo "Installing glfw-x11"
		if pacman -Qs glfw-x11 >/dev/null; then
			echo "glfw-x11 is already installed"
		else
			sudo pacman -S glfw-x11
		fi
	fi
	echo "Checking for CMake"
	if command -v cmake &> /dev/null; then
		echo "CMake is already installed"
	else
		echo "Installing CMake"
		if [[ $OS_MAC == 'Darwin' ]]; then
			curl -LO https://github.com/Kitware/CMake/releases/download/v3.26.2/cmake-3.26.2-macos10.10-universal.tar.gz
			tar -xzf cmake-3.26.2-macos10.10-universal.tar.gz
			rm cmake-3.26.2-macos10.10-universal.tar.gz
		elif [[ $OS_ARCH == *'arch'* ]]; then
			sudo pacman -S cmake
		fi
	fi
	compile_mlx
}
fi
