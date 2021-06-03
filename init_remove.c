/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	init_data(t_data *data)
{
	data->mlx_p = NULL;
	data->win_p = NULL;
	data->image = NULL;
	data->map = NULL;
	data->colors = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->zoom = 1;

	data->point->x = 0;
	data->point->y = 0;
	data->point->z = 0;
}

void	free_arr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	remove_data(t_data *data)
{
	free(data->mlx_p);
	data->mlx_p = NULL;
	free(data->win_p);
	data->win_p = NULL;
	if (data->map)
		free_arr(data->map);
	if (data->colors)
		free_arr(data->colors);
}

void	finish_it(int errnum, t_data *data)
{
	if (errnum != 0)
		display_error(errnum);
	remove_data(data);
	exit (0);
}
