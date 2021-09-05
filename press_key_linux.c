/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

int	press_key(int key, t_data *data)
{
	if (key == KEY_ESC)
		finish_it(0, data);
	else if (key == KEY_PLUS)
		data->zoom++;
	else if (key == KEY_MINUS && data->zoom - 1 > 1)
		data->zoom--;
	else if (key == KEY_ZERO)
		data->color_flag = (!data->color_flag);
	else if (key == KEY_S && (data->iso_angle - STEP_ANGLE >= 0))
		data->iso_angle -= STEP_ANGLE;
	else if (key == KEY_W && (data->iso_angle + STEP_ANGLE <= ISO_MAX_ANGLE))
		data->iso_angle += STEP_ANGLE;
	else if (key == KEY_D)
		data->rot_angle -= STEP_ANGLE;
	else if (key == KEY_A)
		data->rot_angle += STEP_ANGLE;
	else if (key == KEY_UP)
		data->offset.y += STEP_OFFSET;
	else if (key == KEY_DOWN)
		data->offset.y -= STEP_OFFSET;
	else if (key == KEY_RIGHT)
		data->offset.x -= STEP_OFFSET;
	else if (key == KEY_LEFT)
		data->offset.x += STEP_OFFSET;
	else if (key == KEY_MINUS_RIGHT && ((data->zoom_diviser << 1) <= ZOOM_DIVIZER))
		data->zoom_diviser <<= 1;
	else if (key == KEY_PLUS_RIGHT && ((data->zoom_diviser >> 1) >= 1))
		data->zoom_diviser >>= 1;
	return (0);
}

int	krestik(int key, t_data *data)
{
	if (key && data)
	{
		;
	}
	exit(0);
	return (0);
}
