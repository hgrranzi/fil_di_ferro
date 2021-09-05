/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 2 || aka_strlen(argv[1]) < 5 || aka_strcmp(&argv[1][aka_strlen(argv[1]) - 4], ".fdf"))
		finish_it(ERR_ARGS, data);
}

int	count_zoom(int map_width, int map_height)
{
	int	max_len;

	if (map_width > map_height)
		max_len = map_width;
	else
		max_len = map_height;
	return (ZOOM_MAX / max_len);
}

void	count_win_config(t_data *data, int screen_width, int screen_height)
{
	data->win_width = screen_width * WIN_SCALE;
	data->win_height = screen_height * WIN_SCALE;
	data->offset.x = 0;
	data->offset.y = 0;
	data->color_flag = 0;
	data->rot_angle = ROT_ANGLE;
	data->iso_angle = ISO_ANGLE;
}

void	start_mlx(t_data *data)
{
	int	screen_width;
	int	screen_height;

	data->mlx_p = mlx_init();
	data->zoom = count_zoom(data->map_width, data->map_height);
	data->zoom_diviser = ZOOM_DIVIZER;
	mlx_get_screen_size(&screen_width, &screen_height);
	count_win_config(data, screen_width, screen_height);
	data->win_p = mlx_new_window(data->mlx_p, data->win_width, data->win_height, "magic");
	if (!data->win_p)
		finish_it(errno, data);
	data->image->img = mlx_new_image(data->mlx_p, data->win_width, data->win_height);
	if (!data->image->img)
		finish_it(errno, data);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bpp, &data->image->line, &data->image->endian);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_image		image;

	init_data(&data);
	data.image = &image;
	check_args(argc, argv, &data);
	check_config(&data, argv[1]);
	start_mlx(&data);
	mlx_hook(data.win_p, 17, 1L << 0, krestik, &data);
	mlx_hook(data.win_p, 2, 1L << 0, press_key, &data);
	mlx_loop_hook(data.mlx_p, render_image, &data);
	mlx_loop(data.mlx_p);
	return (0);
}
