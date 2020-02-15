#include <stdlib.h>
#include <mlx.h>
#define WIDHT	1000
#define HIGHT	1000

int			close_endian(void *param)
{
	(void)param;
	exit(0);
}

int		key_press(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	int		*draw;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window (mlx_ptr, WIDHT, HIGHT, "Push_swap");
	img_ptr = mlx_new_image (mlx_ptr, WIDHT, HIGHT);
	draw = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	draw[500 + 100 * WIDHT] = 0xff0000;
	mlx_put_image_to_window (mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_pixel_put (mlx_ptr, win_ptr, 100, 100, 0xff);
	mlx_string_put (mlx_ptr, win_ptr, 40, 20, 0xFFFF, "Hello, Mansur");
	mlx_hook(win_ptr, 17, 0, close_endian, 0);
	mlx_hook(win_ptr, 2, 0, key_press, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

//-L minilibx/ -lmlx -framework OpenGL -framework AppKit
