#include "fractol.h"

int get_rgba(int red, int green, int blue, int alpha)
{
    return (red << 24 | green << 16 | blue << 8 | alpha);
}

int get_red(int rgba)
{
    return ((rgba >> 24) & 0xFF);
}

int get_green(int rgba)
{
    return ((rgba >> 16) & 0xFF);
}

int get_blue(int rgba)
{
    return ((rgba >> 8) & 0xFF);
}

int get_alpha(int rgba)
{
    return (rgba & 0xFF);
}
