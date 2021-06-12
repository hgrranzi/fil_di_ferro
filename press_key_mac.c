/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

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
