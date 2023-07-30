#ifndef FRONTEND_H
# define FRONTEND_H

#include "fractol.h"
#include "backend.h"

void ft_key_hook(mlx_key_data_t key, void * param);
void mouse_scroll_hook(double delta_x, double delta_y, void * param);
void mouse_cursor_hook(double xpos, double ypos, void* param);
void ft_window_resize_hook(int32_t width, int32_t height, void * param);
void window_exit_hook(void *param);
void ft_pixel(void *img, int x, int y, int32_t estimator, t_fractol *env);
void compute_frame(t_fractol *env);
int get_rgba(int red, int green, int blue, int alpha);


void	control_red(mlx_key_data_t key, t_fractol *env);
void	control_green(mlx_key_data_t key, t_fractol *env);
void	control_blue(mlx_key_data_t key, t_fractol *env);
void	control_transparency(mlx_key_data_t key, t_fractol *env);

void	go_left(mlx_key_data_t key, t_fractol *env);
void	go_right(mlx_key_data_t key, t_fractol *env);
void	go_up(mlx_key_data_t key, t_fractol *env);
void	go_down(mlx_key_data_t key, t_fractol *env);

void	control_details(mlx_key_data_t key, t_fractol *env);

#endif