#include "../includes/minirt.h"

//inserting color in every single pixel
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

//inizializate the mlx pointer of image and address
void	ft_image_init(t_mlx *mlx)
{
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->x_res, mlx->y_res);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel, \
			&mlx->img.line_length, &mlx->img.endian);
}

int	ft_close_window(t_main *m)
{
	free(m->scn.obj);
	exit(0);
}

//inizializate the mlx and and window setting
void	ft_rt_init(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->aspect_ratio = 16.0f / 9.0f;
	mlx->x_res = 1500;
	mlx->y_res = mlx->x_res / (int)roundf(mlx->aspect_ratio);
	mlx->window = mlx_new_window(mlx->ptr, mlx->x_res, mlx->y_res, "Mini RT");
	mlx_do_key_autorepeaton(mlx->ptr);
}
