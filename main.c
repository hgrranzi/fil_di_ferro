/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 2 || aka_strlen(argv[1]) < 5
	|| aka_strcmp(&argv[1][aka_strlen(argv[1]) - 4], ".fdf"))
		finish_it(ERR_ARGS, data);
}

void	start_mlx(t_data *data)
{
	data->mlx_p = mlx_init();
	data->win_p = mlx_new_window(data->mlx_p, WIN_W, WIN_W, "magic");
	if (!data->win_p)
		finish_it(errno, data);
	data->image->img = mlx_new_image(data->mlx_p, WIN_W, WIN_W);
	if (!data->image->img)
		finish_it(errno, data);
	data->image->addr = mlx_get_data_addr(data->image->img,
		&data->image->bpp, &data->image->line, &data->image->endian);
}

int	press_key(int key, t_data *data)
{
	if (key == 53)
		finish_it(0, data);
	if (key == 24)
		data->zoom += ZOOM / 4; // need a function for zoom and offset change
	else if (key == 27)
		data->zoom -= ZOOM / 4; // need a function for zoom and offset change
	else if (key == 29)
		data->color_flag = (!data->color_flag);
	else if (key == 126)
		data->angle -= 0.05;
	else if (key == 125)
		data->angle += 0.05;
	else if (key == 124)
		data->offset += 16;
	else if (key == 123)
		data->offset -= 16;
	//printf("%d\n", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_image	image;
	t_vector	point;

	data.point = &point;
	init_data(&data);
	data.image = &image;
	check_args(argc, argv, &data);
	check_config(&data, argv[1]);
	start_mlx(&data);
	mlx_hook(data.win_p, 2, 1L << 0, press_key, &data);
	mlx_loop_hook(data.mlx_p, render_image, &data);
	mlx_loop(data.mlx_p);
	return (0);
}
