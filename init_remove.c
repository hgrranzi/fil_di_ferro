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
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
}

void	remove_data(t_data *data)
{
	free(data->mlx_p);
	data->mlx_p = NULL;
	free(data->win_p);
	data->win_p = NULL;
	free(data->map);
	data->map = NULL;
}

void	finish_it(int errnum, t_data *data)
{
	if (errnum != 0)
		display_error(errnum);
	remove_data(data);
	exit (0);
}
