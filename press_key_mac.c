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
		data->zoom++;
	else if (key == 27 && data->zoom - 1 > 1)
		data->zoom--;
	else if (key == 29)
		data->color_flag = (!data->color_flag);
	else if (key == 1 && (data->iso_angle - 0.05 >= 0))
		data->iso_angle -= STEP_ANGLE;
	else if (key == 13 && (data->iso_angle + 0.05 <= ISO_MAX_ANGLE))
		data->iso_angle += STEP_ANGLE;
	else if (key == 2)
		data->rot_angle -= STEP_ANGLE;
	else if (key == 0)
		data->rot_angle += STEP_ANGLE;
	else if (key == 126) // need to change it for linux
		data->offset.y += STEP_OFFSET;
	else if (key == 125)
		data->offset.y -= STEP_OFFSET;
	else if (key == 124)
		data->offset.x -= STEP_OFFSET;
	else if (key == 123)
		data->offset.x += STEP_OFFSET;
	else if (key == 78 && ((data->zoom_diviser << 1) <= ZOOM_DIVIZER))
		data->zoom_diviser <<= 1;
	else if (key == 69 && ((data->zoom_diviser >> 1) >= 1))
		data->zoom_diviser >>= 1;
	return (0);
}

int	krestik(int key, t_data *data)
{
	exit(0);
	return (0);
}
