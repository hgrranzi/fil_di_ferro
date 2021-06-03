/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

int	render_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->image, 0, 0);
	return (0);
}
