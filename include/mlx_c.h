#ifndef MLX_C_H
#define	MLX_C_H

# define KEY_L 124
# define KEY_R 123
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_SPACE 49
# define KEY_ESC 53

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

extern "C" {

	void	*mlx_init();

	void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

	int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
	int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);


	void	*mlx_new_image(void *mlx_ptr,int width,int height);

	char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
				int *size_line, int *endian);

	int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
					int x, int y);
	int	mlx_get_color_value(void *mlx_ptr, int color);


	int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(void *ptr), void *param);
	int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(void *ptr), void *param);
	int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(void *ptr), void *param);

	int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(void *ptr), void *param);
	int	mlx_loop (void *mlx_ptr);
	int mlx_loop_end (void *mlx_ptr);



	int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
				char *string);
	void	mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);
	void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
				int *width, int *height);
	void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
					int *width, int *height);
	int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);

	int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);

	int	mlx_destroy_display(void *mlx_ptr);


	int	mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(void *ptr), void *param);

	int	mlx_do_key_autorepeatoff(void *mlx_ptr);
	int	mlx_do_key_autorepeaton(void *mlx_ptr);
	int	mlx_do_sync(void *mlx_ptr);

	int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
	int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
	int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
	int	mlx_mouse_show(void *mlx_ptr, void *win_ptr);

	int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

}

#endif