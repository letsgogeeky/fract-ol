# Fractals are wonderful

Fractional dimesion!

### Adding MLX42 as a submodule
`git submodule add https://github.com/codam-coding-college/MLX42 lib/MLX42`
If you've already made `git add .` this would result in the MLX repo being added without a reference URL, you'll have to remove it and add it again using:
```bash
git rm --cached lib/MLX42
git submodule add https://github.com/codam-coding-college/MLX42 lib/MLX42
```
This will create a `.gitmodules` file. now you can use `git add .gitmodules` and proceed from that point.


### Compiling MLX42 library on MacOS
1. If you don't have `glfw` and `cmake` you'll need to first install both using:
```bash
brew update
brew upgrade
brew install glfw
brew install cmake
```

2. Now you can build the MLX library using:
```bash
cd MLX42
cmake -B build
cd build
make HEADERS='-I /usr/local/Cellar/glfw/3.3.8/include/' -C ./
```

### Compiling it with an example of your own code
1. Make sure your C code has it included:
```C
#include "lib/MLX42/include/MLX42/MLX42.h"
```

2. Run: `gcc main.c lib/MLX42/build/libmlx42.a -Iinclude -lglfw`

