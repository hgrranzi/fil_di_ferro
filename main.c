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

void	count_win_config(t_data *data, int screen_width, int screen_height)
{
	if (data->map_width > BIG_MAP) // define it
		data->win_width = screen_width;
	else
		data->win_width = screen_width * 3 / 4;
	if (data->map_height > BIG_MAP)
		data->win_height = screen_height;
	else
		data->win_height = screen_height * 3 / 4;
}

void	start_mlx(t_data *data)
{
	int	screen_width;
	int	screen_height;

	data->mlx_p = mlx_init();
	mlx_get_screen_size(&screen_width, &screen_height); // for mac
	//mlx_get_screen_size(data->mlx_p, &screen_width, &screen_height); // for linux
	count_win_config(data, screen_width, screen_height);
	//printf("%d %d", screen_width, screen_height);
	data->win_p = mlx_new_window(data->mlx_p, data->win_width, data->win_height, "magic");
	if (!data->win_p)
		finish_it(errno, data);
	data->image->img = mlx_new_image(data->mlx_p, data->win_width, data->win_height);
	if (!data->image->img)
		finish_it(errno, data);
	data->image->addr = mlx_get_data_addr(data->image->img,
		&data->image->bpp, &data->image->line, &data->image->endian);
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
	//printf("width = %d height = %d", data.map_width, data.map_height);
	start_mlx(&data);
	mlx_hook(data.win_p, 17, 1L << 0, krestik, &data);
	mlx_hook(data.win_p, 2, 1L << 0, press_key, &data);
	mlx_loop_hook(data.mlx_p, render_image, &data);
	mlx_loop(data.mlx_p);
	return (0);
}
