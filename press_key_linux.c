/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

int	press_key(int key, t_data *data)
{
	if (key == 65307)
		finish_it(0, data);
	if (key == 61)
		data->zoom += ZOOM / 4; // need a function for zoom and offset change
	else if (key == 45)
		data->zoom -= ZOOM / 4; // need a function for zoom and offset change
	else if (key == 48)
		data->color_flag = (!data->color_flag);
	else if (key == 65362)
		data->angle -= 0.05;
	else if (key == 65364)
		data->angle += 0.05;
	else if (key == 65363)
		data->offset += 16;
	else if (key == 65361)
		data->offset -= 16;
	//printf("%d\n", key);
	return (0);
}
