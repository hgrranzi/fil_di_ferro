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
	else if (key == 24)
		data->zoom += ZOOM / 10; // need a function for zoom and offset change
	else if (key == 27)
		data->zoom -= ZOOM / 10; // need a function for zoom and offset change
	else if (key == 29)
		data->color_flag = (!data->color_flag);
	/*else if (key == 126)
		data->angle -= 0.05;
	else if (key == 125)
		data->angle += 0.05;*/
	else if (key == 126) // need to change it for linux
		data->offset.y += 16;
	else if (key == 125)
		data->offset.y -= 16;
	else if (key == 124)
		data->offset.x -= 16;
	else if (key == 123)
		data->offset.x += 16;
	//printf("%d\n", key);
	return (0);
}

int	krestik(int key, t_data *data)
{
	exit(0); // check free in finish_it
	return (0);
}
