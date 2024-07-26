#include "fractol.h"

int main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "mandelbrot") == 0 || strcmp(av[1], "julia") == 0)
        fractol(av[1]);
    else
        printf("Usage: ./fractol [mandelbrot | julia]\n");
    return (0);
}